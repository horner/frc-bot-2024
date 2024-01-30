// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <frc2/command/button/Trigger.h>

#include "autos.hpp"
#include "examplecommand.hpp"
#include "robotcontainer.hpp"

RobotContainer::RobotContainer() {
    // Initialize all of your commands and subsystems here

    // Configure the button bindings
    ConfigureBindings();
}

void RobotContainer::ConfigureBindings() {
    // Configure your trigger bindings here

    // Schedule `ExampleCommand` when `exampleCondition` changes to `true`
    frc2::Trigger ([this] { return m_subsystem.ExampleCondition(); })
        .OnTrue (ExampleCommand (&m_subsystem).ToPtr());

    // Schedule `ExampleMethodCommand` when the Xbox controller's B button is
    // pressed, cancelling on release.
    _gamepad.A().WhileTrue (m_subsystem.ExampleMethodCommand());
    _gamepad.B().WhileTrue (m_subsystem.ExampleMethodCommand());
    _gamepad.X().WhileTrue (m_subsystem.ExampleMethodCommand());
    _gamepad.Y().WhileTrue (m_subsystem.ExampleMethodCommand());

    // _gamepad.LeftStick().Debounce(m_subsystem.ExampleMethodCommand());
    // _gamepad.RightStick().WhileTrue(m_subsystem.ExampleMethodCommand());
}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
    // An example command will be run in autonomous
    return autos::ExampleAuto (&m_subsystem);
}
