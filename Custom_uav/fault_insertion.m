%% Used for Fault insertion
%% Created: 2024/4/1
%% Last Update: 2024/4/8
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%% 故障类型
sensor = 0;
actuator = 0;
rotor = 0;

%% 故障注入时间
fault_time_start = 1;

%% 故障初始化
u_sensor_fault = 0;
v_sensor_fault = 0;
w_sensor_fault = 0;

phi_sensor_fault = 0;
theta_sensor_fault = 0;
psi_sensor_fault = 0;

p_sensor_fault = 0;
q_sensor_fault = 0;
r_sensor_fault = 0;

elevator_stuck = 0;
aileron_stuck = 0;
rudder_stuck = 0;

rotor1_fail = 0;
rotor2_fail = 0;
rotor3_fail = 0;
rotor4_fail = 0;

tilt1_fail = 0;
tilt2_fail = 0;

%% 故障模式
if(sensor == 1)
    u_sensor_fault = 0;
    v_sensor_fault = 0;
    w_sensor_fault = 0;

    phi_sensor_fault = 0;
    theta_sensor_fault = 0;
    psi_sensor_fault = 0;

    p_sensor_fault = 0;
    q_sensor_fault = 0;
    r_sensor_fault = 0;
end

if(actuator == 1)
    elevator_stuck = 0; % 升降舵卡死，值为卡死位置，单位：rad
    aileron_stuck = 0.1; % 副翼卡死，值为卡死位置，单位：rad
    rudder_stuck = 0; % 尾舵卡死，值为卡死位置，单位：rad
end

if(rotor == 1)
    rotor1_fail = 0; % 1号电机失效，值为失效时的实际油门
    rotor2_fail = 0; % 2号电机失效，值为失效时的实际油门
    rotor3_fail = 0; % 3号电机失效，值为失效时的实际油门
    rotor4_fail = 0; % 4号电机失效，值为失效时的实际油门

    tilt1_fail = 0; % 1号电机倾转角故障，值为故障时的倾转角
    tilt2_fail = 0; % 2号电机倾转角故障，值为故障时的倾转角
end