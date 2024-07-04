%% Used for Custom EVTOL Flight Mission Estabilish
%% Created: 2024/3/30
%% Last Update: 2024/4/8
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

mission_bus;


%% Setup Hover Mission
HoverMission(1)=struct('mode',1,'position',[0,0,-50]','params',[0;0;0;0]);
HoverMission(2)=struct('mode',2,'position',[100,100,-50]','params',[0;0;0;0]);
HoverMission(3)=struct('mode',2,'position',[100,100,-100]','params',[0;0;0;0]);

% Setup Fixed Wing Mission
FixedWingMission(1)=struct('mode',2,'position',[250,0,-20]','params',[0;0;0;0]);
FixedWingMission(2)=struct('mode',2,'position',[500,0,-20]','params',[0;0;0;0]);
FixedWingMission(3)=struct('mode',2,'position',[750,-100,-20]','params',[0;0;0;0]);
FixedWingMission(4)=struct('mode',2,'position',[2500,-100,-200]','params',[0;0;0;0]);