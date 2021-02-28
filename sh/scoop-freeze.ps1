if (Get-Command $cmdName -errorAction SilentlyContinue)
{
    "$cmdName exists"
}

$output = Get-Process
Write-Output $output

$installedPackages = scoop list

foreach($line in $installedPackages) {
    Write-Output $line
}