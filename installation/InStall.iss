; �ű��� Inno Setup �ű��� ���ɣ�
; �йش��� Inno Setup �ű��ļ�����ϸ��������İ����ĵ���

[Setup]
; ע��: AppId ֵ����Ψһʶ���Ӧ�ó���
; ��ֹ������Ӧ�ó���İ�װ��ʹ����ͬ�� AppId ֵ��
; (��Ҫ����һ���µ� GUID����ѡ�񡰹��� | ���� GUID����)
AppId={{91848919-7E0A-4AD2-BBFE-FD405BF47FD2}}
AppName=��������
AppVersion=1.0.0.1
AppCopyright=Copyright (C) 2005-2015 , Inc.
AppComments=ĳĳ��˾
VersionInfoVersion=1.0.0.1
VersionInfoDescription=��Ʒ����
AppPublisher=������
AppPublisherURL=http://www.��˾��ַ.com/
AppSupportURL=http://www.��˾��ַ.com/
AppUpdatesURL=http://www.��˾��ַ.com/
DefaultDirName={pf}\ReadCard
DefaultGroupName=ReadCard
AllowNoIcons=yes
OutputDir=.\
OutputBaseFilename=��װ������
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

; ע��: ��Ҫ���κι���ϵͳ�ļ���ʹ�á�Flags: ignoreversion��

[Icons]
Name: "{group}\{cm:UninstallProgram,ж�س���}"; Filename: "{uninstallexe}"


[Registry]
;Root: HKLM; Subkey: "SOFTWARE\Samwoo\AA\TIP"; ValueType: string; ValueName: "ConnectionString"; ValueData:"Provider=SQLOLEDB.1;Password=sa;Persist Security Info=True;User ID=sa;Initial Catalog=TF_CMS;Data Source=10.1.86.129"; Flags:createvalueifdoesntexist    uninsdeletekey

