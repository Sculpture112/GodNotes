param(
    [Parameter(Mandatory = $true, Position = 0)]
    [ValidatePattern('^\d{3}$')]
    [string]$Lesson,

    [string]$TemplatePath = 'C:\template.cpp'
)

$ErrorActionPreference = 'Stop'

$projectRoot = Split-Path -Parent $PSScriptRoot
$sourceDir = Join-Path $projectRoot '母题'
$targetDir = Join-Path (Join-Path $projectRoot 'God') '母题'

if (-not (Test-Path -LiteralPath $sourceDir -PathType Container)) {
    throw "母题目录不存在：$sourceDir"
}
if (-not (Test-Path -LiteralPath $TemplatePath -PathType Leaf)) {
    throw "模板文件不存在：$TemplatePath"
}

$lessonPrefix = [regex]::Escape($Lesson)
$sourceFiles = @(Get-ChildItem -LiteralPath $sourceDir -File -Filter "$Lesson*.md" |
    Where-Object { $_.BaseName -match "^$lessonPrefix(?:\s|$)" } |
    Sort-Object Name)

if ($sourceFiles.Count -eq 0) {
    throw "在 $sourceDir 中未找到课程 $Lesson 的母题文件。"
}

if (-not (Test-Path -LiteralPath $targetDir -PathType Container)) {
    New-Item -ItemType Directory -Path $targetDir | Out-Null
}

$created = 0
$skipped = 0
foreach ($sourceFile in $sourceFiles) {
    $targetFile = Join-Path $targetDir ($sourceFile.BaseName + '.cpp')
    if (Test-Path -LiteralPath $targetFile) {
        Write-Output "已跳过（已存在）：$targetFile"
        $skipped++
        continue
    }

    Copy-Item -LiteralPath $TemplatePath -Destination $targetFile
    Write-Output "已创建：$targetFile"
    $created++
}

Write-Output "课程 $Lesson：创建 $created 个，跳过 $skipped 个。"
