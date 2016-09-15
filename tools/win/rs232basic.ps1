# Script to upload a BASIC file over the RS-232 port to a Challenger 1P

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

