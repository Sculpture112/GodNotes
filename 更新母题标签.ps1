$ErrorActionPreference = 'Stop'

$root = $PSScriptRoot
$algorithmDir = Join-Path $root '算法名'
$target = Join-Path $root '母题标签.md'

if (-not (Test-Path -LiteralPath $algorithmDir -PathType Container)) {
    throw "找不到算法名文件夹：$algorithmDir"
}

$names = @(Get-ChildItem -LiteralPath $algorithmDir -File -Filter '*.md' |
    Sort-Object Name |
    ForEach-Object { $_.BaseName })

if ($names.Count -eq 0) {
    throw "算法名文件夹中没有 .md 文件：$algorithmDir"
}

$lines = @('# 母题标签', '') + @($names | ForEach-Object { '- ' + $_ })
$content = [string]::Join([Environment]::NewLine, $lines) + [Environment]::NewLine
$encoding = New-Object System.Text.UTF8Encoding($false)

if (-not (Test-Path -LiteralPath $target -PathType Leaf) -or
    [System.IO.File]::ReadAllText($target, [System.Text.Encoding]::UTF8) -cne $content) {
    [System.IO.File]::WriteAllText($target, $content, $encoding)
    Write-Output "已更新母题标签.md：$($names.Count) 条"
} else {
    Write-Output "母题标签.md 已是最新：$($names.Count) 条"
}
