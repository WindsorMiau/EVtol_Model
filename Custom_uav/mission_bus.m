function mission_bus() 
% MISSION_BUS initializes a set of bus objects in the MATLAB base workspace 

% Bus object: doubleUAVPathManagerBus 
clear elems;
elems(1) = Simulink.BusElement;
elems(1).Name = 'mode';
elems(1).Dimensions = [1 1];
elems(1).DimensionsMode = 'Fixed';
elems(1).DataType = 'uint8';
elems(1).Complexity = 'real';
elems(1).Min = [];
elems(1).Max = [];
elems(1).DocUnits = '';
elems(1).Description = '';

elems(2) = Simulink.BusElement;
elems(2).Name = 'position';
elems(2).Dimensions = [3 1];
elems(2).DimensionsMode = 'Fixed';
elems(2).DataType = 'double';
elems(2).Complexity = 'real';
elems(2).Min = [];
elems(2).Max = [];
elems(2).DocUnits = '';
elems(2).Description = '';

elems(3) = Simulink.BusElement;
elems(3).Name = 'params';
elems(3).Dimensions = [4 1];
elems(3).DimensionsMode = 'Fixed';
elems(3).DataType = 'double';
elems(3).Complexity = 'real';
elems(3).Min = [];
elems(3).Max = [];
elems(3).DocUnits = '';
elems(3).Description = '';

doubleUAVPathManagerBus = Simulink.Bus;
doubleUAVPathManagerBus.HeaderFile = '';
doubleUAVPathManagerBus.Description = '';
doubleUAVPathManagerBus.DataScope = 'Auto';
doubleUAVPathManagerBus.Alignment = -1;
doubleUAVPathManagerBus.PreserveElementDimensions = 0;
doubleUAVPathManagerBus.Elements = elems;
clear elems;
assignin('base','doubleUAVPathManagerBus', doubleUAVPathManagerBus);

