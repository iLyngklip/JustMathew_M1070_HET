		
		
		

		class complexGearbox
		{
			GearboxRatios[] = {"R1",-2.475,"N",0,"D1",2.367,"D2",1.67,"D3",1.238,"D4",0.99,"D5",0.802,"D6",0.601};
			TransmissionRatios[] = {"High",5.1};
			gearBoxMode = "auto";
			moveOffGear = 1;
			driveString = "D";
			neutralString = "N";
			reverseString = "R";
		};
		simulation = "carx";
		dampersBumpCoef = 3.0;
		differentialType = "all_limited";
		frontRearSplit = 0.5;
		frontBias = 1.3;
		rearBias = 1.3;
		centreBias = 1.3;
		clutchStrength = 20.0;
		enginePower = 141;
		maxOmega = 302;
		peakTorque = 870;
		dampingRateFullThrottle = 0.08;
		dampingRateZeroThrottleClutchEngaged = 2.0;
		dampingRateZeroThrottleClutchDisengaged = 0.35;

		torqueCurve[] = {
			{ 0.0,0.17 },
			{ 0.25,0.65 },
			{ 0.35,0.75 },
			{ 0.461,1.0 },
			{ 0.6,0.95 },
			{ 0.7,0.85 },
			{ 0.8,0.75 },
			{ 1.0,0.5 }};
		changeGearMinEffectivity[] = {0.95,0.15,0.95,0.95,0.95,0.95,0.95};
		switchTime = 0.31;
		latency = 1.0;
		class Wheels
		{
			class LF
			{
				boneName = "wheel_1_1_damper";
				steering = 1;
				side = "left";
				center = "wheel_1_1_axis";
				boundary = "wheel_1_1_bound";
				width = "0.126";
				mass = 25;
				MOI = 18.8; //28.8
				dampingRate = 0.2;
				maxBrakeTorque = 55000;
				maxHandBrakeTorque = 3500;
				suspTravelDirection[] = {0,-1,0};
				suspForceAppPointOffset = "wheel_1_1_axis";
				tireForceAppPointOffset = "wheel_1_1_axis";
				maxCompression = 0.3;
				mMaxDroop = 0.3;
				sprungMass = 1475;
				springStrength = 62625;
				springDamperRate = 6920;
				longitudinalStiffnessPerUnitGravity = 10000;
				latStiffX = 25;
				latStiffY = 180;
				frictionVsSlipGraph[] = {
					{ 0,1 },
					{ 0.5,1 },
					{ 1,1 }};
			};
			class LR: LF
			{
				boneName = "wheel_1_2_damper";
				steering = 0;
				center = "wheel_1_2_axis";
				boundary = "wheel_1_2_bound";
				suspForceAppPointOffset = "wheel_1_2_axis";
				tireForceAppPointOffset = "wheel_1_2_axis";
				maxHandBrakeTorque = 3500;
			};
			class RF: LF
			{
				boneName = "wheel_2_1_damper";
				center = "wheel_2_1_axis";
				boundary = "wheel_2_1_bound";
				suspForceAppPointOffset = "wheel_2_1_axis";
				tireForceAppPointOffset = "wheel_2_1_axis";
				steering = 1;
				side = "right";
			};
			class RR: RF
			{
				boneName = "wheel_2_2_damper";
				steering = 0;
				center = "wheel_2_2_axis";
				boundary = "wheel_2_2_bound";
				suspForceAppPointOffset = "wheel_2_2_axis";
				tireForceAppPointOffset = "wheel_2_2_axis";
				maxHandBrakeTorque = 3500;
			};
		};