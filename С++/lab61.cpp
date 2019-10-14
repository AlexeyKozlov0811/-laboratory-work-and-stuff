#include <iostream>
#include <string.h>
#include <conio.h>
#include <Windows.h>
#include <intrin.h>
#include <comdef.h>
#include <Wbemidl.h>
using namespace std;

#pragma warning(disable : 4996)

int GetCountOfProcessorsFromMask(ULONG_PTR *Mask)
{
	unsigned int ProcessorsCount = 0;

	for (int i = 0; i < (sizeof(Mask) << 3) - 1; i++)
	{
		if (*Mask & (1 << i)) ProcessorsCount++;
	}
	return ProcessorsCount;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	cout << "\n���������� ��� ��� ����'�����\n";
	
	char buffer[MAX_COMPUTERNAME_LENGTH+1];
	DWORD size;
	size=sizeof(buffer);
	GetComputerName(buffer,&size);
	cout << "��'� ���������\t - " << buffer << endl;
	
	char NameBuffer[MAX_PATH];
	char SysNameBuffer[MAX_PATH];
	DWORD VSNumber;
	DWORD MCLength;
	DWORD FileSF;

	cout << "\n���������� ������������ ����'�����\n";
	if (GetVolumeInformation("D:\\",NameBuffer, sizeof(NameBuffer),
		&VSNumber,&MCLength,&FileSF,SysNameBuffer,sizeof(SysNameBuffer)))
	{
		cout <<  NameBuffer << endl;
		cout << "������� �������\t - " << SysNameBuffer << endl;
		cout << "������� �����\t - " << VSNumber << endl;
	}

	cout << "\n���������� ��� ����������� ��������\n";
	
	int CPUInfo[4] = {-1};
	__cpuid(CPUInfo, 0x80000000);
	unsigned int nExIds = CPUInfo[0];
	char CPUBrandString[64] = {0};
	for (unsigned int i = 0x80000000; i <= nExIds; ++i)
	{
		__cpuid(CPUInfo, i);
		if (i == 0x80000002)
		{
			memcpy(CPUBrandString, CPUInfo, sizeof(CPUInfo));
		}
		else if (i == 0x80000003)
		{
			memcpy(CPUBrandString + 16, CPUInfo, sizeof(CPUInfo));
		}
		else if (i == 0x80000004)
		{
			memcpy(CPUBrandString + 32, CPUInfo, sizeof(CPUInfo));
		}
	}
	cout << "�������� \t\t - " << CPUBrandString << endl;
	
	SYSTEM_INFO SystemInfo;
	GetNativeSystemInfo(&SystemInfo);
	cout << "����������� ��������� \t - ";
	switch (SystemInfo.wProcessorArchitecture)
	{
	case PROCESSOR_ARCHITECTURE_AMD64:
		cout << "x64";
		break;
	case PROCESSOR_ARCHITECTURE_ARM:
		cout << "ARM";
		break;
	case PROCESSOR_ARCHITECTURE_IA64:
		cout << "Intel Itanium";
		break;
	case PROCESSOR_ARCHITECTURE_INTEL:
		cout << "Intel x86";
		break;
	case PROCESSOR_ARCHITECTURE_UNKNOWN:
		cout << "Unknown";
		break;
	}
	cout << endl;
	
	PSYSTEM_LOGICAL_PROCESSOR_INFORMATION Buffer = NULL;
	PSYSTEM_LOGICAL_PROCESSOR_INFORMATION Ptr = NULL;

	unsigned long Length = 0;
	unsigned long Offset = 0;
	unsigned int NUMANodesCount = 0;
	unsigned int PhysicalProcessorsCount = 0;
	unsigned int LogicalProcessorsCount = 0;
	unsigned int ProcessorCoresCount = 0;
	
	while (!GetLogicalProcessorInformation(Buffer, &Length))
	{
		if (GetLastError() == ERROR_INSUFFICIENT_BUFFER)
		{
			if (Buffer) free(Buffer);
			Buffer = (PSYSTEM_LOGICAL_PROCESSOR_INFORMATION)malloc(Length);
			if (!Buffer)
			{
				cout << "\nError: Allocation failure" << endl;
				return -1;
			}
		}
		else
		{
			cout << "\nError : " << GetLastError() << endl;
			return -1;
		}
	}
	Ptr = Buffer;
	while (Offset < Length)
	{
		switch (Ptr->Relationship)
		{
		case RelationNumaNode:
			NUMANodesCount++;
			break;
		case RelationProcessorCore:
			ProcessorCoresCount++;
			LogicalProcessorsCount += GetCountOfProcessorsFromMask(&Ptr->ProcessorMask);
			break;
		case RelationCache:
			break;
		case RelationProcessorPackage:
			PhysicalProcessorsCount++;
			break;
		default:
			cout << "\nError: Unsupported LOGICAL_PROCESSOR_RELATIONSHIP value." << endl;
			break;
		}
		Offset += sizeof(SYSTEM_LOGICAL_PROCESSOR_INFORMATION);
		Ptr++;
	}
	cout << "Գ������ ��������� \t - " << PhysicalProcessorsCount << endl;
	cout << "������� ��������� \t - " << LogicalProcessorsCount << endl;
	cout << "���� \t\t\t - " << ProcessorCoresCount << endl;
	
	cout << "\n���������� ��� ���'���\n";
	MEMORYSTATUSEX MemoryStatus;
	MemoryStatus.dwLength = sizeof(MEMORYSTATUSEX);

	GlobalMemoryStatusEx(&MemoryStatus);

	cout << "������ ������� ���'��\t\t - " << (MemoryStatus.ullTotalPhys >> 20) << " ��" << endl;
	cout << "³���� ������� ���'��\t - " << (MemoryStatus.ullAvailPhys >> 20) << " ��" << endl;
	cout << "������ ����� ��������\t\t - " << (MemoryStatus.ullTotalPageFile >> 20) << " ��" << endl;
	cout << "³����� ����� ��������\t\t - " << (MemoryStatus.ullAvailPageFile >> 20) << " ��" << endl;
	cout << "������ ��������� ���'��\t - " << (MemoryStatus.ullTotalVirtual >> 20) << " ��" << endl;
	cout << "³���� ��������� ���'��\t - " << (MemoryStatus.ullAvailVirtual >> 20) << " ��" << endl;
	cout << "��������� ��������� ���'��\t - " << (MemoryStatus.ullAvailExtendedVirtual >> 20) << " ��" << endl;
	cout << "������������ ���'��\t\t - " << MemoryStatus.dwMemoryLoad << "%" << endl;
	
	OSVERSIONINFO osvi;
    BOOL bIsWindowsXPorLater;

    ZeroMemory(&osvi, sizeof(OSVERSIONINFO));
    osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
    GetVersionEx(&osvi);
	int version=osvi.dwMajorVersion;
	cout << "\n���������� ��� ����� �� - ";
	switch (version)
	{
		case(4):
		{
			cout << "Windows 95";
			break;
		}
		case(5):
		{
			cout << "Windows XP";
			break;
		}
		case(6):
		{
			cout << "Windows 10";
			break;
		}
	}
	cout << endl;
	
	//system("systeminfo");

	getchar();
	getchar();
}