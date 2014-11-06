; 脚本由 Inno Setup 脚本向导 生成！
; 有关创建 Inno Setup 脚本文件的详细资料请查阅帮助文档！

[Setup]
; 注意: AppId 值用于唯一识别该应用程序。
; 禁止对其他应用程序的安装器使用相同的 AppId 值！
; (若要生成一个新的 GUID，请选择“工具 | 生成 GUID”。)
AppId={{91848919-7E0A-4AD2-BBFE-FD405BF47FD2}}
AppName=程序名称
AppVersion=1.0.0.1
AppCopyright=Copyright (C) 2005-2015 , Inc.
AppComments=某某公司
VersionInfoVersion=1.0.0.1
VersionInfoDescription=产品描述
AppPublisher=发布者
AppPublisherURL=http://www.公司网址.com/
AppSupportURL=http://www.公司网址.com/
AppUpdatesURL=http://www.公司网址.com/
DefaultDirName={pf}\ReadCard
DefaultGroupName=ReadCard
AllowNoIcons=yes
OutputDir=.\
OutputBaseFilename=安装包名称
Compression=lzma2/ultra
SolidCompression=yes
PrivilegesRequired=admin

ArchitecturesInstallIn64BitMode=x64 ia64

[Languages]
Name: "chinese"; MessagesFile: "ChineseSimplified.isl"

[Tasks]
;Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked
;Name: "quicklaunchicon"; Description: "{cm:CreateQuickLaunchIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

[Files]
Source: "..\bin\ReadCard.dll"; DestDir: "{app}"; Flags: regserver 32bit 
Source: "..\bin\kpaylink2.dll"; DestDir: "{app}"; Flags:replacesameversion 32bit
Source: "C:\Windows\System32\MFC42.dll"; DestDir: "{app}"; Flags: 32bit  

; 注意: 不要在任何共享系统文件上使用“Flags: ignoreversion”

[Icons]
Name: "{group}\{cm:UninstallProgram,卸载程序}"; Filename: "{uninstallexe}"


[Registry]
;Root: HKLM; Subkey: "SOFTWARE\Samwoo\AA\TIP"; ValueType: string; ValueName: "ConnectionString"; ValueData:"Provider=SQLOLEDB.1;Password=sa;Persist Security Info=True;User ID=sa;Initial Catalog=TF_CMS;Data Source=10.1.86.129"; Flags:createvalueifdoesntexist    uninsdeletekey

