<#
.SYNOPSIS

Upload BASIC file over the RS-232 port to a Challenger 1P

.DESCRIPTION

This script uploads BASIC files over the RS-232 interface of an
Ohio Scientific Challenger 1P. The computer must have been put into
load mode with the LOAD command. The script sends a configurable
number of NULL bytes before each line.

.PARAMETER baudrate

Baud rate of the serial port

.PARAMETER nullbytes

Number of NULL bytes to send before each line

.PARAMETER comport

Windows COM port

.PARAMETER infile

BASIC file to upload

#>

param (
    [string]$baudrate = 300,
    [string]$nullbytes = 3,
    [Parameter(Mandatory=$true)][string]$comport,
    [Parameter(Mandatory=$true)][string]$infile
)

$infilepath = Resolve-Path $infile

$nulls = [Byte[]] (,0 * $nullbytes)

$port = new-Object System.IO.Ports.SerialPort $comport, $baudrate, None, 8, one
$port.NewLine = "`r"
$port.Open()
$reader = [System.IO.File]::OpenText($infilepath)
try {
    for() {
        $line = $reader.ReadLine()
        if ($line -eq $null) { break }

        # Write the NULL bytes before each line
        $port.Write($nulls, 0, $nulls.Count)

        # process the line
        $port.WriteLine($line)

        # echo the line to the shell
        $line
    }
}
finally {
    $reader.Close()
    $port.Close()
}
