@echo off
set TARGET_PATH=%~dp0..\bin\main.exe
set SHORTCUT_PATH=%~dp0..\Batalha_Naval.lnk
set ICON_PATH=%~dp0..\img\ship.ico

powershell -Command "$ws = New-Object -ComObject WScript.Shell; $s = $ws.CreateShortcut('%SHORTCUT_PATH%'); $s.TargetPath = '%TARGET_PATH%'; $s.IconLocation = '%ICON_PATH%'; $s.Save()"
