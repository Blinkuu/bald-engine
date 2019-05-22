//
// Created by blinku on 06.05.19.
//

#pragma once

/**
 * This is the engine's entry point.
 */

#ifdef LINUX

int main() {

    auto* application = Bald::Application::Create();

    application->Run();

    delete application;
}

#endif