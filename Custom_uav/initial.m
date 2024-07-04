%% Project Mobius EVTOL飞行器初始化程序
%% 搭配 Project_Mobius.slx使用
%% 创建日期 2023/12/18
%% 上次修改 2023/3/11
%% version:1.0.7
%% author:WindsorMiau
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%% 飞行模式，0为垂直起降，1为巡航
flight_mode = 1;
trim = 1; % 是否需要初始配平，1为是，0为否，配平会尽力维持所设置的总速度

%% 初始化
% 初始位置，单位：m
init_x = 0;  %正方向是北
init_y = 0;  %正方向是东
init_h = 10;  %正方向是上，在simulink里会自己转成NED的，不用操心

% 初始惯性系速度，单位：m/s （正常人类的大脑无法直接给出本体系速度）
init_vx = 16; %正方向是北 为了保证航向的正确计算，不建议都设为0，南北向就给vx一个值，东西向就给vy一个值
init_vy = 0; %正方向是东
init_vz = 0; %正方向是上
init_V = sqrt(init_vx^2 + init_vy^2 + init_vz^2);

% 初始姿态角，单位：rad
init_theta = 0; %正方向是抬头
init_phi = 0;   %正方向是往右滚，不过没特别的事最好保持这里是0
init_psi = 0;

% 惯性系到机体系坐标转换矩阵
matrix_e2b = [                             cos(init_theta)*cos(init_psi)                                           cos(init_theta)*sin(init_psi)                           -sin(init_theta);            
              sin(init_theta)*cos(init_psi)*sin(init_phi)-sin(init_psi)*cos(init_phi) sin(init_theta)*sin(init_psi)*sin(init_phi)+cos(init_psi)*cos(init_phi) cos(init_theta)*sin(init_phi);
              sin(init_theta)*cos(init_psi)*cos(init_phi)+sin(init_psi)*sin(init_phi) sin(init_theta)*sin(init_psi)*cos(init_phi)-cos(init_psi)*sin(init_phi) cos(init_theta)*cos(init_phi)];

% 初始机体系三轴速度，单位：m/s
Vb = matrix_e2b * [init_vx;init_vy;-init_vz];
init_u = Vb(1);
init_v = Vb(2);
init_w = Vb(3);

% 风轴系中的一些角度
init_alpha = atan(init_w/init_u);
init_beta = atan(init_v/init_V);

% 风轴系到本体系的坐标转换矩阵
matrix_w2b = [cos(init_alpha)*cos(init_beta) -cos(init_alpha)*sin(init_beta) -sin(init_alpha);
              sin(init_beta)                  cos(init_beta)                 0;
              sin(init_alpha)*cos(init_beta) -sin(init_alpha)*sin(init_beta) cos(init_alpha)];

% 初始机体系三轴角速度，单位：rad/s，不过正常人类应该不会碰这个
init_p = 0;
init_q = 0;
init_r = 0;

%% 环境参数，只要在地球上就应该不用改这个
rho = 1.2250; %% 大气密度，单位：kg/m^3
g = 9.8060; %% 重力加速度，单位：N/kg

%% 飞行器参数
aircraft_mass = 6.031; %% 飞行器重量，单位：kg
aircraft_b = 2; %% 飞行器主翼翼展，单位：m
aircraft_c = 0.275; %% 飞行器平均几何弦长，单位：m

% 飞行器转动惯量，单位：kg·m^2
Ixx = 0.267; 
Iyy = 0.267;
Izz = 0.375;
Ixz = 0;
Ixy = 0;
Iyz = 0;

I_initial = [Ixx Ixy Ixz;
             Ixy Iyy Iyz;
             Ixz Iyz Izz];

% 转动方程相关量
sigma = Ixx*Izz - Ixz*Ixz;
c1 = ((Iyy - Izz)*Izz - Ixz*Ixz)/sigma;
c2 = ((Ixx - Iyy + Izz)*Ixz)/sigma;
c3 = Izz/sigma;
c4 = Ixz/sigma;
c5 = (Izz - Ixx)/Iyy;
c6 = Ixz/Iyy;
c7 = 1/Iyy;
c8 = (Ixx*(Ixx - Iyy) + Ixz*Ixz)/sigma;
c9 = Ixx/sigma;

%% 动力电机参数
rotor_type = 'RX-78-02'; %% 电机名称
RPM_init = 0; %% 发动机初始转速，转/Min
Max_RPM = 10000; %% 发动机最大转速，转/Min
PropDiameter = 0.3052; %% 旋翼直径，m
rotor_n = 1;

% 发动机安装位置，m
rotor_arm1 = [0.375,0.375,0];
rotor_arm2 = [0.375,-0.375,0];
rotor_arm3 = [-0.375,-0.375,0];
rotor_arm4 = [-0.375,0.375,0];

% 桨叶旋转方向，1为顺时针，-1为逆时针
rotor1_direction = 1;
rotor2_direction = -1;
rotor3_direction = -1;
rotor4_direction = 1;

% 发动机初始倾转角，单位：rad
tilt1_init = pi/2*flight_mode;
tilt2_init = pi/2*flight_mode;
tilt3_init = 0;
tilt4_init = 0;

init_elevator = 0;
init_aileron  = 0;
init_rudder = 0;

%% 气动参数
% 阻力
CDmin = 0.06047;
K = 0.1328;
CL_CDmin = 0.4806;
CdDe = 0.016043;
CdDr = 0.0097403;
CdDa = 0.092132;

CD_fuselage = 0.027;

% 侧力
CYb = -0.00157;
CYDr = 0.128915;
CYp = -0.00157;
CYr = 0.18368;

% 升力
CL0 = 0.81857;
CLa = 4.09127;
CLa_dot = 0;
CLDe = 0.50787;
CLDa = -0.85291;
CLq = 7.31097;

% 滚转力矩
Clb = -0.00161;
ClDa = 0.286593;
ClDr = 0.013407;
Clp = -0.47584;
Clr = 0.27153;

% 俯仰力矩
Cm0 = 0.00763;
Cma = -1.76966;
CmDe = -1.83747;
Cmq = -19.22663;

% 偏航力矩
Cnb = 0.0918;
CnDa = 0.0049274;
CnDr = -0.067036;
Cnp = -0.13267;
Cnr = -0.08829;


%% 配平量计算
% 垂直起降阶段
if flight_mode == 0 && trim == 1
    init_aileron = 0;
    init_rudder = 0;
    aoa = -14*pi/180;
    init_elevator = 0;
    % CL = CL0 + CLDe*init_elevator + CLa*(aoa);
    % CD = CDmin + K*(CL - CL_CDmin)^2 + CdDe*abs(init_elevator);
    % CY = 0;
    Q = 0.5*rho*init_V^2;
    FD_fuselage = -1.*CD_fuselage*init_V*[init_u;init_v;init_w];
    
    % L = Q*aircraft_c*aircraft_b*(-CL);
    % D = Q*aircraft_c*aircraft_b*(-CD);
    % Y = Q*aircraft_c*aircraft_b*CY;
    % 
    % Fa_b = matrix_w2b*[D;Y;L];
    Fx = FD_fuselage(1);
    Fz = aircraft_mass*g +  FD_fuselage(3);
    F_T2 = (+Fz*0.375)/(4*0.375);

    error = 2;
    
    % 二元非线性方程组迭代解
    rotor_n = 100;
    lambda = 0;
    while abs(error) > 2e-14
          J = init_V/(PropDiameter*rotor_n);
          c_1 = 0.03338;
          c_2 = 0.1265;
          c_3 = 0.1210;
          c_4 = 0.1142;
          C_T = c_1*J^3 -c_2*J^2 - c_3*J + c_4;
          F_T = C_T*rho*rotor_n^2*PropDiameter^4;
          f1 = F_T*2*sin(lambda) + Fx;
          f2 = F_T*2*cos(lambda) + F_T2*2 - Fz;

          fx = 4*sin(lambda)*((-c_1*init_V^3*PropDiameter/(rotor_n)^2) - c_3*init_V*PropDiameter^3 + 2*c_4*rotor_n*PropDiameter^4)*rho;
          fy = 4*cos(lambda)*(c_1*init_V^3*PropDiameter/rotor_n - c_2*init_V^2*PropDiameter^2 - c_3*init_V*rotor_n*PropDiameter^3 + c_4*rotor_n^2*PropDiameter^4)*rho;
          gx = 2*cos(lambda)*((-c_1*init_V^3*PropDiameter/(rotor_n)^2) - c_3*init_V*PropDiameter^3 + 2*c_4*rotor_n*PropDiameter^4)*rho;
          gy = -2*sin(lambda)*(c_1*init_V^3*PropDiameter/rotor_n - c_2*init_V^2*PropDiameter^2 - c_3*init_V*rotor_n*PropDiameter^3 + c_4*rotor_n^2*PropDiameter^4)*rho;
          sigma = gx*fy - fx*gy;
          n_step = (f1*(gy) - f2*(fy))/sigma;
          lambda_step = (f2*(fx) - f1*(gx))/sigma;
          
          error = max(abs(n_step),abs(lambda_step));
          rotor_n = rotor_n + n_step;
          lambda = lambda + lambda_step;
    end
    tilt1_init = lambda;
    tilt2_init = lambda;
    RPM1_init = rotor_n * 60;
    RPM2_init = rotor_n * 60;

    n_trim = 100;
    n_step = 1;
    while abs(n_step)>2e-14
          J = init_V/(PropDiameter*n_trim);
          c_1 = 0.03338;
          c_2 = 0.1265;
          c_3 = 0.1210;
          c_4 = 0.1142;
          C_T = c_1*J^3 -c_2*J^2 - c_3*J + c_4;
          F_Ts = C_T*rho*n_trim^2*PropDiameter^4;
          f1s = F_Ts - F_T2;
          
          fn = 2*((-c_1*init_V^3*PropDiameter/(n_trim)^2) - c_3*init_V*PropDiameter^3 + 2*c_4*n_trim*PropDiameter^4)*rho;
          n_step = f1s/fn;
          n_trim = n_trim - n_step;
    end
    RPM3_init = n_trim * 60;
    RPM4_init = n_trim * 60;
% 巡航飞行阶段    
elseif flight_mode == 1 && trim == 1
    Q = 0.5*rho*init_V^2;
    init_aileron = 0;
    init_rudder = 0;

    alpha_trim = 0;
    elevator_trim = 0;
    error = 2;
    % 二元非线性方程组迭代解
    while abs(error)>4e-17
        f1 = Q*aircraft_b*aircraft_c*(CDmin+K*(CL0+CLa*alpha_trim+CLDe*elevator_trim-CL_CDmin)^2+CdDe*abs(elevator_trim))*sin(alpha_trim)...
            +Q*aircraft_b*aircraft_c*(CL0+CLa*alpha_trim+CLDe*elevator_trim)*cos(alpha_trim) - aircraft_mass*g*cos(alpha_trim) + CD_fuselage*init_V*(sin(alpha_trim)*cos(init_psi)*init_vx + sin(alpha_trim)*sin(init_psi)*init_vy);
        f2 = Cm0 + Cma*alpha_trim + CmDe*elevator_trim;

        fx = Q*aircraft_b*aircraft_c*(CDmin+K*(CL0+CLa*alpha_trim+CLDe*elevator_trim-CL_CDmin)^2+CdDe*abs(elevator_trim))*cos(alpha_trim)...
            +Q*aircraft_b*aircraft_c*(2*K*(CL0+CLa*alpha_trim+CLDe*elevator_trim-CL_CDmin)*CLa)*sin(alpha_trim)...
            +Q*aircraft_b*aircraft_c*CLa*cos(alpha_trim)...
            -Q*aircraft_b*aircraft_c*(CL0+CLa*alpha_trim+CLDe*elevator_trim)*sin(alpha_trim) + aircraft_mass*g*sin(alpha_trim)...
            +CD_fuselage*init_V*(-cos(alpha_trim)*cos(init_psi)*init_vx - cos(alpha_trim)*sin(init_psi)*init_vy);
        fy = Q*aircraft_b*aircraft_c*(2*K*(CL0+CLa*alpha_trim+CLDe*abs(elevator_trim)-CL_CDmin)*CLDe-CdDe)*sin(alpha_trim)...
            +Q*aircraft_b*aircraft_c*CLDe*cos(alpha_trim);
        gx = Cma;
        gy = CmDe;

        sigma = gx*fy - fx*gy;
        alpha_step = (f1*(gy) - f2*(fy))/sigma;
        elevator_step = (f2*(fx) - f1*(gx))/sigma;

        error = max(alpha_step,elevator_step);
        alpha_trim = alpha_trim + alpha_step;
        elevator_trim = elevator_trim + elevator_step;
    end
    init_alpha = alpha_trim;
    init_elevator = elevator_trim;
    init_theta = init_alpha;

    CL = CL0 + CLDe*init_elevator + CLa*(init_alpha);
    CD = CDmin + K*(CL - CL_CDmin)^2 + CdDe*abs(init_elevator);
    CY = 0;
    
    matrix_e2b = [                             cos(init_theta)*cos(init_psi)                                           cos(init_theta)*sin(init_psi)                           -sin(init_theta);            
              sin(init_theta)*cos(init_psi)*sin(init_phi)-sin(init_psi)*cos(init_phi) sin(init_theta)*sin(init_psi)*sin(init_phi)+cos(init_psi)*cos(init_phi) cos(init_theta)*sin(init_phi);
              sin(init_theta)*cos(init_psi)*cos(init_phi)+sin(init_psi)*sin(init_phi) sin(init_theta)*sin(init_psi)*cos(init_phi)-cos(init_psi)*sin(init_phi) cos(init_theta)*cos(init_phi)];

    matrix_w2b = [cos(init_alpha)*cos(init_beta) -cos(init_alpha)*sin(init_beta) -sin(init_alpha);
              sin(init_beta)                  cos(init_beta)                 0;
              sin(init_alpha)*cos(init_beta) -sin(init_alpha)*sin(init_beta) cos(init_alpha)];

    Vb = matrix_e2b * [init_vx;init_vy;-init_vz];
    init_u = Vb(1);
    init_v = Vb(2);
    init_w = Vb(3);

    FD_fuselage = -1.*CD_fuselage*init_V*[init_u;init_v;init_w];
    
    L = Q*aircraft_c*aircraft_b*(-CL);
    D = Q*aircraft_c*aircraft_b*(-CD);
    Y = Q*aircraft_c*aircraft_b*CY;
    
    mg = matrix_e2b*[0;0;aircraft_mass*g];

    Fa_b = matrix_w2b*[D;Y;L];
    Fx = Fa_b(1) + FD_fuselage(1) + mg(1);
    Fz = mg(3) + Fa_b(3) + FD_fuselage(3);
    
    
    n_trim = 100;
    n_step = 1;
    while abs(n_step)>2e-14
          J = init_V/(PropDiameter*n_trim);
          c_1 = 0.03338;
          c_2 = 0.1265;
          c_3 = 0.1210;
          c_4 = 0.1142;
          C_T = c_1*J^3 -c_2*J^2 - c_3*J + c_4;
          F_T = C_T*rho*n_trim^2*PropDiameter^4;
          f1 = F_T*2 + Fx;
          
          fn = 2*((-c_1*init_V^3*PropDiameter/(n_trim)^2) - c_3*init_V*PropDiameter^3 + 2*c_4*n_trim*PropDiameter^4)*rho;
          n_step = f1/fn;
          n_trim = n_trim - n_step;
    end
    rotor_n = n_trim;
    RPM1_init = rotor_n * 60;
    RPM2_init = rotor_n * 60;
    RPM3_init = 0;
    RPM4_init = 0;
end