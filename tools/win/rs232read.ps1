<#
.SYNOPSIS

Read from serial port. Null bytes are ignored.

.DESCRIPTION

.PARAMETER baudrate

Baud rate of the serial port

.PARAMETER timeout

Timeout in ms after which the read loop is terminated

.PARAMETER comport

Windows COM port

.PARAMETER outfile

Output file

#>

param (
    [string]$baudrate = 300,
    [int]$timeout = 10000,
    [Parameter(Mandatory=$true)][string]$comport,
    [Parameter(Mandatory=$true)][string]$outfile
)

$port = New-Object System.IO.Ports.SerialPort $comport, $baudrate, None, 8, one
$port.ReadTimeout = $timeout
$port.Open()
$file = New-Object System.IO.FileStream($outfile, [System.IO.FileMode]::Create)
try {
    while ($true)
    {
        $byte = $port.ReadByte()
        if ($byte -ne 0)
        {
	        $file.WriteByte($byte)
            Write-Host -NoNewline ([char] $byte)
        }
    }
}
catch [System.TimeoutException]
{
    Write-Host "Timeout detected, closing output file"
}
finally
{
    $file.Close()
}
$port.Close()
