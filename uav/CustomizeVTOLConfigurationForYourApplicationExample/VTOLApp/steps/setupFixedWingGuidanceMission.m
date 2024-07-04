% Setup Fixed Wing configuration.
FSState=flightState.FixedWing;

% Set Test Bench to execute complex guidance mission
TestMode=1;

% Set guidance type to execute fixed wing mission.
guidanceType=1;

% Enable Visualization
Visualization = 1;

%Disable Sensors
SensorType=0;

% Setup Fixed Wing Mission
FixedWingMission(1)=struct('mode',2,'position',[250,0,-20]','params',[0;0;0;0]);
FixedWingMission(2)=struct('mode',2,'position',[500,0,-20]','params',[0;0;0;0]);
FixedWingMission(3)=struct('mode',2,'position',[750,-100,-20]','params',[0;0;0;0]);
FixedWingMission(4)=struct('mode',2,'position',[2500,-100,-200]','params',[0;0;0;0]);
% FixedWingMission(5)=struct('mode',3,'position',[1500,-150,-120]','params',[90;-1;3;0]);
% FixedWingMission(6)=struct('mode',3,'position',[250,-250,-20]','params',[50;-1;3;0]);