#include "AutonomousCommand.h"
#include "DriveDistanceCommand.h"
#include "IntakeForwardBack2.h"
#include "IntakeUpDown.h"
#include "ReleaseCatapultCommand.h"
#include "ResetCatapultCommand.h"
#include "../RobotMap.h"
#include "ShootBallIntoGoalGroup.h"
#include "ReleaseCatapultCommand2.h"

AutonomousCommand::AutonomousCommand() {
        // Add Commands here:
        // e.g. AddSequential(new Command1());
        //      AddSequential(new Command2());
        // these will run in order.

        // To run multiple commands at the same time,
        // use AddParallel()
        // e.g. AddParallel(new Command1());
        //      AddSequential(new Command2());
        // Command1 and Command2 will run in parallel.

        // A command group will require all of the subsystems that each member
        // would require.
        // e.g. if Command1 requires chassis, and Command2 requires arm,
        // a CommandGroup containing them would require both the chassis and the
        // arm.
	
	AddSequential(new DriveDistanceCommand(-20, 0.5));
	AddParallel(new IntakeForwardBack2(false, 0.5));
	AddSequential(new IntakeUpDown(false, 3.0));
#if 1
	printf("Autonomous point 1\n");
	AddSequential(new ReleaseCatapultCommand2(
			1.0, 
			.236
	));
	printf("Autonomous Point 2\n");
	AddSequential(new ResetCatapultCommand());	
	printf("Autonomous Point 3\n");
#else
	AddSequential(new ShootBallIntoGoalGroup());
#endif
}
