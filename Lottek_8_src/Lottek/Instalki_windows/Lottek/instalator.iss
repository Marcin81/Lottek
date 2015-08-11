; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

[Setup]
AppName=Du�y Lottek
AppVerName=Du�y Lottek 1.3 Beta
AppPublisher=unemployed81
AppPublisherURL=http://duzylottek.zzl.org
AppSupportURL=http://duzylottek.zzl.org
AppUpdatesURL=http://duzylottek.zzl.org
DefaultDirName={pf}\Du�y Lottek
DefaultGroupName=Du�y Lottek
LicenseFile=C:\instalki\Lottek\license.txt
InfoBeforeFile=C:\instalki\Lottek\before.txt
Compression=lzma
SolidCompression=yes

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked
Name: "quicklaunchicon"; Description: "{cm:CreateQuickLaunchIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

[Files]
Source: "C:\instalki\Lottek\Lottek.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\instalki\Lottek\QtCore4.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\instalki\Lottek\QtGui4.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\instalki\Lottek\QtNetwork4.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\instalki\Lottek\mingwm10.dll"; DestDir: "{app}"; Flags: ignoreversion

; NOTE: Don't use "Flags: ignoreversion" on any shared system files

[INI]
Filename: "{app}\Lottek.url"; Section: "InternetShortcut"; Key: "URL"; String: "http://duzylottek.zzl.org"

[Icons]
Name: "{group}\Du�y Lottek"; Filename: "{app}\Lottek.exe"
Name: "{group}\{cm:ProgramOnTheWeb,Du�y Lottek}"; Filename: "{app}\Lottek.url"
Name: "{group}\{cm:UninstallProgram,Du�y Lottek}"; Filename: "{uninstallexe}"
Name: "{userdesktop}\Du�y Lottek"; Filename: "{app}\Lottek.exe"; Tasks: desktopicon
Name: "{userappdata}\Microsoft\Internet Explorer\Quick Launch\Du�y Lottek"; Filename: "{app}\Lottek.exe"; Tasks: quicklaunchicon

[Run]
Filename: "{app}\Lottek.exe"; Description: "{cm:LaunchProgram,Du�y Lottek}"; Flags: nowait postinstall skipifsilent

[UninstallDelete]
Type: files; Name: "{app}\Lottek.url"
