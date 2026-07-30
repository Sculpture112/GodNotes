@ECHO OFF
@SETLOCAL
@FOR %%I IN ("%~dp0..\excalidraw") DO @SET "EXCALIDRAW_OBSIDIAN_DIR=%%~fI"
@node "%USERPROFILE%\.codex\skills\excalidraw-skill\scripts\export-obsidian.mjs" %*
