
class CfgPatches
{
	class JustMathew_Vehicles
	{
		units[] = {"JustMathew_M1070_05"};
		weapons[] = {};
		requiredVersion = 0.01;
		requiredAddons[] = {"A3_Soft_F"};
	};

};

class DefaultEventhandlers;

class CfgVehicles
{
	class Car;
	class Car_F: Car
	{
		class HitPoints /// we want to use hitpoints predefined for all cars
		{
			class HitLFWheel;
			class HitLF2Wheel;

			class HitRFWheel;
			class HitRF2Wheel;
			class HitBody;

			class HitGlass1;
			class HitGlass2;
			class HitGlass3;
			class HitGlass4;
		};	
	};

	
	class Truck_F: Car_F
	{
		class ViewPilot;
		class HitPoints: Hitpoints
		{
			class HitLFWheel;
			class HitLBWheel;
			class HitLMWheel;
			class HitLF2Wheel;
			class HitRFWheel;
			class HitRBWheel;
			class HitRMWheel;
			class HitRF2Wheel;
			class HitBody;
			class HitGlass1;
			class HitGlass2;
			class HitGlass3;
			class HitGlass4;
			class HitGlass5;
			class HitGlass6;
		};
		class AnimationSources;
	};
	
	
	class Truck_01_base_F: Truck_F
	{
		class AnimationSources: AnimationSources
		{
			
		};
		
	};
	
	
	class JustMathew_M1070_05_base: Truck_01_base_F
	{
		model 	= "JustMathew_M1070_5\JustMathew_M1070_05.p3d";  /// simple path to model
		picture	= "\A3\Weapons_F\Data\placeholder_co.paa"; /// just some icon in command bar
		Icon	= "\A3\Weapons_F\Data\placeholder_co.paa"; /// icon in map	
		
		
		category = "Car";
		side = 1;
		insideSoundCoef = 0.4;
		displayName = "M1070 HET Truck"; /// displayed in Editor
		
		driverDoor = "DoorL";
		cargoDoors[] = {"DoorR"};

		
		hiddenSelections[] = {"camo1"}; ///we want to allow changing of colours
		
		terrainCoef 	= 6.5; 	/// different surface affects this car more, stick to tarmac
		turnCoef 		= 2.5; 	/// should match the wheel turn radius
		precision 		= 10; 	/// how much freedom has the AI for its internal waypoints - lower number means more precise but slower approach to way
		brakeDistance 	= 3.0; 	/// how many internal waypoints should the AI plan braking in advance
		acceleration 	= 15; 	/// how fast acceleration does the AI think the car has
		
		fireResistance 	= 5; 	/// lesser protection against fire than tanks
		armor 			= 32; 	/// just some protection against missiles, collisions and explosions
		cost			= 50000; /// how likely is the enemy going to target this vehicle
		
		transportMaxBackpacks 	= 3; /// just some backpacks fit the trunk by default
		transportSoldier 		= 1; /// number of cargo except driver
		
		/// some values from parent class to show how to set them up
		wheelDamageRadiusCoef 	= 0.9; 			/// for precision tweaking of damaged wheel size
		wheelDestroyRadiusCoef 	= 0.4;			/// for tweaking of rims size to fit ground
		maxFordingDepth 		= 0.5;			/// how high water would damage the engine of the car
		waterResistance 		= 1;			/// if the depth of water is bigger than maxFordingDepth it starts to damage the engine after this time
		crewCrashProtection		= 0.25;			/// multiplier of damage to crew of the vehicle => low number means better protection
		driverLeftHandAnimName 	= "drivewheel"; /// according to what bone in model of car does hand move
		driverRightHandAnimName = "drivewheel";	/// beware, non-existent bones may cause game crashes (even if the bones are hidden during play)
		
	
		
		class Turrets{}; /// doesn't have any gunner nor commander
		class HitPoints : HitPoints
		{
			class HitLFWheel:HitLFWheel	{armor=0.125; passThrough=0;}; /// it is easier to destroy wheels than hull of the vehicle
			class HitLF2Wheel:HitLF2Wheel{armor=0.125; passThrough=0;};

			class HitRFWheel:HitRFWheel	{armor=0.125; passThrough=0;};
			class HitRF2Wheel:HitRF2Wheel{armor=0.125; passThrough=0;}; 

			class HitFuel 			{armor=0.50; material=-1; name="fueltank"; visual=""; passThrough=0.2;}; /// correct points for fuel tank, some of the damage is aFRLied to the whole
			class HitEngine 		{armor=0.50; material=-1; name="engine"; visual=""; passThrough=0.2;};
			class HitBody: HitBody 	{name = "body"; visual="camo1"; passThrough=1;}; /// all damage to the hull is aFRLied to total damage

			class HitGlass1:HitGlass1 {armor=0.25;}; /// it is pretty easy to puncture the glass but not so easy to remove it
			class HitGlass2:HitGlass2 {armor=0.25;};
			class HitGlass3:HitGlass3 {armor=0.25;};
			class HitGlass4:HitGlass4 {armor=0.25;};
		};
	
		driverAction 		= driver_offroad01; /// what action is going the driver take inside the vehicle. Non-existent action makes the vehicle inaccessible
		cargoAction[] 		= {passenger_low01, passenger_generic01_leanleft, passenger_generic01_foldhands}; /// the same of all the crew
		getInAction 		= GetInLow; 		/// how does driver look while getting in
		getOutAction 		= GetOutLow; 		/// and out
		cargoGetInAction[] 	= {"GetInLow"}; 	/// and the same for the rest, if the array has fewer members than the count of crew, the last one is used for the rest
		cargoGetOutAction[] = {"GetOutLow"}; 	/// that means all use the same in this case
		
		#include "sounds.hpp"	/// sounds are in a separate file 
		
		#include "physX.hpp"	/// PhysX settings are in a separate file 
		
		
		
		class AnimationSources: AnimationSources
		{
			class ramp_rotation
			{
				source = "user";
				initPhase = 0; // start position
				animPeriod = 2; // seconds
				
				
				
			};
		};
		
		
		
		
		class UserActions
		{
			// Actions you can do with the truck!
			class drive_ramp_down
			{
				displayName 		= "Ramp down";
				displayNameDefault 	= "";
				radius 				= 5;
				position 			= "ramp_controls";
				// animPeriod			= 2;
				onlyForPlayer		= false;
				condition			= "this animationPhase ""ramp_rotation"" < 0.5";
				statement 			= "this animate [""ramp_rotation"", 1];";
			};
			
			class drive_ramp_up: drive_ramp_down
			{
				displayName 		= "Ramp up";
				condition			= "this animationPhase ""ramp_rotation"" > 0.5";
				statement 			= "this animate [""ramp_rotation"", 0];";
			};
		};
		

		
	};
	
	class JustMathew_M1070_05: JustMathew_M1070_05_base /// some class that is going to be visible in editor
	{	
		scope	= 2; 			/// makes the car visible in editor
		crew 	= "C_man_1"; 	/// we need someone to fit into the car
		side	= 3; 			/// civilian car should be on civilian side
		faction	= CIV_F;		/// and with civilian faction
		
		
		hiddenSelections[] = {"camo1"}; // What to texture
		hiddenSelectionsTextures[] = {"JustMathew_M1070_5\M1070_fullTexture_co.paa"};	 /// we could use any texture to cover the car
		
		
		// Stuff for vehicle-in-vehicle transport
		class VehicleTransport
		{
			class Carrier
			{
				cargoBayDimensions[] 	= {"VTV_limit_1", "VTV_limit_2"};	// Cargobay size
				disableHeightLimit		= 1;
				maxLoadMass				= 200000000; // in Kg
				cargoAlignment[]		= {"front", "center"};
				cargoSpacing[] 			= {0, 0.15, 0}; // Offset X, Y, Z
				exits[]					= {"VTV_exit_1"};
				unloadingInterval		= 20; // Seconds it takes to unload
				loadingDistance			= 10;	// Max distance in meters for loading
				loadingAngle			= 60;	// Max alignment angle between the two
			};
		};
	};	
	
	class JustMathew_M1070_05_green : JustMathew_M1070_05
	{
		scope = 2;
		displayName = "M1070 HET Truck Green"; /// displayed in Editor
		hiddenSelectionsTextures[] = {"JustMathew_M1070_5\M1070_fullTexture_green_co.paa"};	 /// we could use any texture to cover the car
	};
};
