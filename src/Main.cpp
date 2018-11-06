#include "Install.h"

#include <thread>

int __attribute__((constructor)) Startup()
{
    std::thread installThread(Installer::installGladiator);

    installThread.detach();

    return 0;
}

void __attribute__((destructor)) Shutdown()
{
    Installer::uninstallGladiator();
}
