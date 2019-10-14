#include <iostream>
#include <string.h>
#include <conio.h>
#include <Windows.h>
#include <intrin.h>

using namespace std;

#pragma warning(disable : 4996)

int GetCountOfProcessorsFromMask(unsigned long *Mask)
{
	int ProcessorsCount = 0;

	for (int i = 0; i < (sizeof(Mask) << 3) - 1; i++)
	{
		if (*Mask & (1 << i)) ProcessorsCount++;
	}
	return ProcessorsCount;
}

void InfoLine(char *Info)
{
	if (!Info) return;
	int i = 29;

	while (i--)
		cout << "=";
	cout << "[" << Info << "]";

	i = 28 - strlen(Info);
	while (i--)
		cout << "=";
	cout << "=" << endl;
}

int main()
{
	InfoLine((char*)"CPU");
	int CPUInfo[4] = { -1 };
	__cpuid(CPUInfo, 0x80000000);
	unsigned int nExIds = CPUInfo[0];

	char CPUBrandString[64] = { 0 };
	for (unsigned int i = 0x80000000; i <= nExIds; ++i)
	{
		__cpuid(CPUInfo, i);

		if (i == 0x80000002)
		{
			memcpy(CPUBrandString,
				CPUInfo,
				sizeof(CPUInfo));
		}
		else if (i == 0x80000003)
		{
			memcpy(CPUBrandString + 16,
				CPUInfo,
				sizeof(CPUInfo));
		}
		else if (i == 0x80000004)
		{
			memcpy(CPUBrandString + 32, CPUInfo, sizeof(CPUInfo));
		}
	}

	cout << "Cpu String \t\t: " << CPUBrandString << endl;

	SYSTEM_INFO SystemInfo;

	GetNativeSystemInfo(&SystemInfo);

	cout << "Processor Architecture \t: ";



	switch (SystemInfo.wProcessorArchitecture)
	{
	case PROCESSOR_ARCHITECTURE_AMD64:
		cout << "x64";
		break;
	case PROCESSOR_ARCHITECTURE_ARM:
		cout << "ARM";
		break;
		//	case PROCESSOR_ARCHITECTURE_ARM64:
		//		cout << "x64";
		//	break;
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

	/*	if(SystemInfo.wProcessorArchitecture != PROCESSOR_ARCHITECTURE_UNKNOWN)
	{
	cout <<" - based"<<endl;
	}*/
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
				return (2);
			}
		}
		else
		{
			cout << "\nError : " << GetLastError() << endl;
			return (3);
		}
	}



	Ptr = Buffer;

	while (Offset  < Length)
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

	cout << "Physical CPUs \t\t: " << PhysicalProcessorsCount << endl;
	cout << "Logical CPUs \t\t: " << LogicalProcessorsCount << endl;
	cout << "Cores \t\t\t: " << ProcessorCoresCount << endl;
	InfoLine((char*)"Memory");
	MEMORYSTATUSEX MemoryStatus;
	MemoryStatus.dwLength = sizeof(MEMORYSTATUSEX);

	GlobalMemoryStatusEx(&MemoryStatus);

	cout << "Total physical memory\t: " << (MemoryStatus.ullTotalPhys >> 20) << " MB" << endl;
	cout << "Free physical memory\t: " << (MemoryStatus.ullAvailPhys >> 20) << " MB" << endl;
	cout << "Total page file\t\t: " << (MemoryStatus.ullTotalPageFile >> 20) << " MB" << endl;
	cout << "Free page file\t\t: " << (MemoryStatus.ullAvailPageFile >> 20) << " MB" << endl;
	cout << "Total virtual memory\t: " << (MemoryStatus.ullTotalVirtual >> 20) << " MB" << endl;
	cout << "Free virtual memory\t: " << (MemoryStatus.ullAvailVirtual >> 20) << " MB" << endl;
	cout << "Extended virtual memory\t: " << (MemoryStatus.ullAvailExtendedVirtual >> 20) << " MB" << endl;
	cout << "Memory utilization\t: " << MemoryStatus.dwMemoryLoad << "%" << endl;
	/*InfoLine((char*)"OS");

	OSVERSIONINFO   OSInfo;
	ZeroMemory(&OSInfo, sizeof(OSVERSIONINFO));
	OSInfo.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);*/

	//cout << "OS\t\t\t: Windows ";
	//GetVersionExW((LPOSVERSIONINFOW)&OSInfo);
	////	GetVersionExW

	//switch (OSInfo.dwMajorVersion)
	//{
	//case 10:
	//	cout << "10"; break;
	//case 6:
	//	switch (OSInfo.dwMinorVersion)
	//	{
	//	case 3: cout << "8.1"; break;
	//	case 2: cout << "8"; break;
	//	case 1: cout << "7"; break;
	//	case 0: cout << "Vista"; break;
	//	}
	//	break;
	//case 5:
	//	switch (OSInfo.dwMinorVersion)
	//	{
	//	case 2:
	//		if ((SystemInfo.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64))cout << "XP Professional x64 Edition";
	//		break;
	//	case 1: cout << "XP"; break;
	//	case 0: cout << "2000"; break;
	//	}
	//	break;
	//}


	//cout << endl;
	//cout << "Version\t\t\t: " << OSInfo.dwMajorVersion << "." << OSInfo.dwMinorVersion << endl;

	system("systeminfo");

	system("pause");
}