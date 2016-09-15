# Basic script to upload an binary file over the RS-232 port to a
# Challenger 1P

param (
    [string]$baudrate = 300,
    [Parameter(Mandatory=$true)][string]$comport,
    [Parameter(Mandatory=$true)][string]$infile
)

$port = new-Object System.IO.Ports.SerialPort $comport, $baudrate, None, 8, one
$content = [IO.File]::ReadAllBytes($infile)
$port.Open()
$port.Write($content, 0, $content.Count)
$port.Close()
