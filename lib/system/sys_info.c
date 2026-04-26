#include <stdio.h>
#include <windows.h>

char *get_number_of_processors(SYSTEM_INFO info)
{
  char *buffer = malloc(sizeof(char) * 2);
  GetSystemInfo(&info);
  snprintf(buffer, 32, "%lu", info.dwNumberOfProcessors);
  return buffer;
}

char *get_systems_total_ram(MEMORYSTATUSEX memInfo)
{
  char *buffer = malloc(sizeof(char) * 4);
  GlobalMemoryStatusEx(&memInfo);
  snprintf(buffer, 64, "%llu", (memInfo.ullTotalPhys / (1024 * 1024)));
  strcat(buffer, " MB\0");
  return buffer;
}

char *get_systems_available_ram(MEMORYSTATUSEX memInfo)
{
  char *buffer = malloc(sizeof(char) * 4);
  GlobalMemoryStatusEx(&memInfo);
  snprintf(buffer, 64, "%llu", (memInfo.ullAvailPhys / (1024 * 1024)));
  strcat(buffer, " MB\0");
  return buffer;
}

char *get_systems_memory_load(MEMORYSTATUSEX memInfo)
{
  char *buffer = malloc(sizeof(char) * 3);
  GlobalMemoryStatusEx(&memInfo);
  snprintf(buffer, 64, "%lu", (memInfo.dwMemoryLoad));
  strcat(buffer, " %\0");
  return buffer;
}

char *get_system_name()
{
  char *computerName = malloc((MAX_COMPUTERNAME_LENGTH + 1) * sizeof(char));
  DWORD size = sizeof(computerName);
  if (GetComputerName(computerName, &size))
    return computerName;
  return "null\0";
}

int main()
{
  SYSTEM_INFO info;
  MEMORYSTATUSEX memInfo;
  memInfo.dwLength = sizeof(memInfo);

  // num_of_processes = getNumberOfProcessors()
  // print(num_of_processors)
  char *num_of_processes = get_number_of_processors(info);
  printf("%s \n", num_of_processes);

  // total_ram = getSystemRam()
  // print(num_of_processors)
  char *total_ram = get_systems_total_ram(memInfo);
  printf("%s \n", total_ram);

  // available_ram = getAvailableRam()
  // print(available_ram)
  char *available_ram = get_systems_available_ram(memInfo);
  printf("%s \n", available_ram);

  // mem_load = getMemoryLoad()
  // print(mem_load)
  char *mem_load = get_systems_memory_load(memInfo);
  printf("%s \n", mem_load);

  // pc_name = getSystemName()
  // print(pc_name)
  char *pc_name = get_system_name();
  printf("%s \n", pc_name);

  return 0;
}
