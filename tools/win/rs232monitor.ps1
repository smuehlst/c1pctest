<#
.SYNOPSIS

Upload a file over the RS-232 port to a Challenger 1P into the PROM monitor

.DESCRIPTION

This script uploads a file over the RS-232 port into the Challenger 1P
PROM monitor. The file must consist of a sequence of commands and hex digits
that could be typed in in PROM monitor mode.

Example file contents (switch to address mode, enter address 0x200,
switch to data mode, enter bytes A2, FF, 9A, D8):

.0200/A2
FF
9A
D8
<etc.>

.PARAMETER baudrate

Baud rate of the serial port

.PARAMETER comport

Windows COM port

.PARAMETER infile

File to upload

#>

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
