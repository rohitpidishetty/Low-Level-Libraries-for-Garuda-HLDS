#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#include <sys/utsname.h>
#ifdef __APPLE__
#include <sys/types.h>
#include <sys/sysctl.h>
#endif
#ifdef __linux__
#include <sys/sysinfo.h>
#endif
#endif

char *get_number_of_processors()
{
  char *buffer = malloc(32);

#ifdef _WIN32
  SYSTEM_INFO info;
  GetSystemInfo(&info);
  snprintf(buffer, 32, "%lu", info.dwNumberOfProcessors);
#else
  long cores = sysconf(_SC_NPROCESSORS_ONLN);
  snprintf(buffer, 32, "%ld", cores);
#endif

  return buffer;
}

char *get_systems_total_ram()
{
  char *buffer = malloc(64);

#ifdef _WIN32
  MEMORYSTATUSEX memInfo;
  memInfo.dwLength = sizeof(memInfo);
  GlobalMemoryStatusEx(&memInfo);
  snprintf(buffer, 64, "%llu MB",
           (unsigned long long)(memInfo.ullTotalPhys / (1024 * 1024)));

#elif __linux__
  struct sysinfo info;
  sysinfo(&info);
  snprintf(buffer, 64, "%lu MB",
           (info.totalram / (1024 * 1024)));

#elif __APPLE__
  int64_t mem;
  size_t len = sizeof(mem);
  sysctlbyname("hw.memsize", &mem, &len, NULL, 0);
  snprintf(buffer, 64, "%lld MB",
           (long long)(mem / (1024 * 1024)));
#endif

  return buffer;
}

char *get_systems_available_ram()
{
  char *buffer = malloc(64);

#ifdef _WIN32
  MEMORYSTATUSEX memInfo;
  memInfo.dwLength = sizeof(memInfo);
  GlobalMemoryStatusEx(&memInfo);
  snprintf(buffer, 64, "%llu MB",
           (unsigned long long)(memInfo.ullAvailPhys / (1024 * 1024)));

#elif __linux__
  struct sysinfo info;
  sysinfo(&info);
  snprintf(buffer, 64, "%lu MB",
           (info.freeram / (1024 * 1024)));

#elif __APPLE__
  snprintf(buffer, 64, "Not directly available");
#endif

  return buffer;
}

char *get_systems_memory_load()
{
  char *buffer = malloc(32);

#ifdef _WIN32
  MEMORYSTATUSEX memInfo;
  memInfo.dwLength = sizeof(memInfo);
  GlobalMemoryStatusEx(&memInfo);
  snprintf(buffer, 32, "%lu %%", memInfo.dwMemoryLoad);
#else
  snprintf(buffer, 32, "Not available");
#endif

  return buffer;
}

char *get_system_name()
{
  char *buffer = malloc(256);

#ifdef _WIN32
  DWORD size = 256;
  GetComputerName(buffer, &size);

#else
  gethostname(buffer, 256);
#endif

  return buffer;
}

int main()
{
  

  // num_of_processes = getNumberOfProcessors()
  // print(num_of_processors)
  char *num_of_processes = get_number_of_processors();
  printf("%s \n", num_of_processes);

  // total_ram = getSystemRam()
  // print(num_of_processors)
  char *total_ram = get_systems_total_ram();
  printf("%s \n", total_ram);

  // available_ram = getAvailableRam()
  // print(available_ram)
  char *available_ram = get_systems_available_ram();
  printf("%s \n", available_ram);

  // mem_load = getMemoryLoad()
  // print(mem_load)
  char *mem_load = get_systems_memory_load();
  printf("%s \n", mem_load);

  // pc_name = getSystemName()
  // print(pc_name)
  char *pc_name = get_system_name();
  printf("%s \n", pc_name);

  return 0;
}
