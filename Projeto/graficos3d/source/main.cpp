// Copyright (c) 2026 Igor Ianes
// Licensed under the MIT License.

#include "Manager.hpp"

int main(int argc, char *argv[])
{
    Manager *engine = Manager::Instance();

    if (engine->Init())
    {
        engine->Run();
    }

    Manager::Release();
    engine = NULL;

    return 0;
}