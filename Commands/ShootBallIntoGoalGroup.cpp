#include "ShootBallIntoGoalGroup.h"
#include "ReleaseCatapultCommand.h"
#include "ResetCatapultCommand.h"
#include "../RobotMap.h"
#include "IntakeForwardBack2.h"
#include "IntakeUpDown.h"

ShootBallIntoGoalGroup::ShootBallIntoGoalGroup() {
    // these will run in order.
	//AddParallel(new IntakeForwardBack2(false, 0.3));
	AddSequential(new IntakeUpDown(false, 0.8));
	AddSequential(new ReleaseCatapultCommand(
			SHOOT_FOR_THE_GOAL_POWER, 
			SHOOT_FOR_THE_GOAL_DURATION
	));
	AddSequential(new ResetCatapultCommand());
}
