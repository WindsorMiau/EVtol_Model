%% Used for Custom EVTOL simulator analysis
%% Created: 2024/1/30
%% Last Update: 2024/3/1
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


time_start = 1;
time_over = length(out.mission_out);

time_stamp = time_start + 1;
mission_list = [];
mission_list(end + 1,:) = [out.mission_out(time_start),time_start];
%% Mission Specification
while time_stamp <= time_over
    if(out.mission_done(time_stamp)==0 && out.mission_done(time_stamp - 1)==1)
        mission_list(end,3) = time_stamp - 1;
        if(out.mission_out(time_stamp)~=7)
            mission_list(end+1,1) = out.mission_out(time_stamp);
            mission_list(end,2) = time_stamp;
        end
    else if(out.mission_done(time_stamp)==1 && out.mission_done(time_stamp - 2)==0 && out.mission_out(time_stamp)==7)
        mission_list(end,3) = time_stamp - 1;
    end
    end
    time_stamp = time_stamp + 1;
end

if(out.mission_out(time_stamp - 1)~=7)
    mission_list(end,3) = time_stamp - 1;
end



plotfigure.position = 1;
plotfigure.velocity = 1;
plotfigure.Rotors = 1;
plotfigure.controlsurface = 1;
plotfigure.attitude = 1;


%% Position
if plotfigure.position == 1
    figure('Name','Position');
    Xe = out.Result_Xe(time_start:mission_list(end,3),1);
    Ye = out.Result_Xe(time_start:mission_list(end,3),2);
    altitude = -out.Result_Xe(time_start:mission_list(end,3),3);
    time = out.tout(time_start:mission_list(end,3));
    
    subplot(3,1,3);
    set(gca,'FontName','Times New Roman','FontSize',10.5);
    hold on
    plot(time,altitude,'Color','k','LineWidth',1.5);
    title('Altitude-Time');
    xlabel('time/s');
    ylabel('altitude/m');
    for i = 1:length(mission_list(:,1))
        if(mission_list(i,1) ~= 1)
        line([time(mission_list(i,3)) time(mission_list(i,3))],ylim,'linestyle','--','color','r','LineWidth',1.5);
        end
    end
    hold off
    
    subplot(3,1,1);
    set(gca,'FontName','Times New Roman','FontSize',10.5);
    hold on
    plot(time,Xe,'Color','k','LineWidth',1.5);
    title('Xe-Time');
    xlabel('time/s');
    ylabel('Xe/m');
    for i = 1:length(mission_list(:,1))
        if(mission_list(i,1) ~= 1)
        line([time(mission_list(i,3)) time(mission_list(i,3))],ylim,'linestyle','--','color','r','LineWidth',1.5);
        end
    end
    hold off
    
    subplot(3,1,2);
    set(gca,'FontName','Times New Roman','FontSize',10.5);
    hold on
    plot(time,Ye,'Color','k','LineWidth',1.5);
    title('Ye-Time');
    xlabel('time/s');
    ylabel('Ye/m');
    for i = 1:length(mission_list(:,1))
        if(mission_list(i,1) ~= 1)
        line([time(mission_list(i,3)) time(mission_list(i,3))],ylim,'linestyle','--','color','r','LineWidth',1.5);
        end
    end
    hold off
end

%% Velocity
if plotfigure.velocity == 1
    figure('Name','Velocity');
    Vx = out.Result_Ve(time_start:mission_list(end,3),1);
    Vy = out.Result_Ve(time_start:mission_list(end,3),2);
    Vz = -out.Result_Ve(time_start:mission_list(end,3),3);
    
    subplot(3,1,1);
    set(gca,'FontName','Times New Roman','FontSize',10.5);
    hold on
    plot(time,Vx,'Color','k','LineWidth',1.5);
    title('Vx-Time');
    xlabel('time/s');
    ylabel('Vx/m·s^-1');
    for i = 1:length(mission_list(:,1))
        if(mission_list(i,1) ~= 1)
        line([time(mission_list(i,3)) time(mission_list(i,3))],ylim,'linestyle','--','color','r','LineWidth',1.5);
        end
    end
    hold off
    
    subplot(3,1,2);
    set(gca,'FontName','Times New Roman','FontSize',10.5);
    hold on
    plot(time,Vy,'Color','k','LineWidth',1.5);
    title('Vy-Time');
    xlabel('time/s');
    ylabel('Vy/m·s^-1');
    for i = 1:length(mission_list(:,1))
        if(mission_list(i,1) ~= 1)
        line([time(mission_list(i,3)) time(mission_list(i,3))],ylim,'linestyle','--','color','r','LineWidth',1.5);
        end
    end
    hold off
    
    subplot(3,1,3);
    set(gca,'FontName','Times New Roman','FontSize',10.5);
    hold on
    plot(time,Vz,'Color','k','LineWidth',1.5);
    title('Vz-Time');
    xlabel('time/s');
    ylabel('Vz/m·s^-1');
    for i = 1:length(mission_list(:,1))
        if(mission_list(i,1) ~= 1)
        line([time(mission_list(i,3)) time(mission_list(i,3))],ylim,'linestyle','--','color','r','LineWidth',1.5);
        end
    end
    hold off
end

%% Rotors
if plotfigure.Rotors == 1
    figure('Name','RPM');
    rotor1 = 60.*out.Result_Real_Rotor(time_start:mission_list(end,3),1);
    rotor2 = 60.*out.Result_Real_Rotor(time_start:mission_list(end,3),2);
    rotor3 = 60.*out.Result_Real_Rotor(time_start:mission_list(end,3),3);
    rotor4 = 60.*out.Result_Real_Rotor(time_start:mission_list(end,3),4);
    
    subplot(2,2,1);
    set(gca,'FontName','Times New Roman','FontSize',10.5);
    hold on
    plot(time,rotor1,'Color','k','LineWidth',1.5);
    title('Rotor1 RPM');
    xlabel('time/s');
    ylabel('RPM');
    for i = 1:length(mission_list(:,1))
        if(mission_list(i,1) ~= 1)
        line([time(mission_list(i,3)) time(mission_list(i,3))],ylim,'linestyle','--','color','r','LineWidth',1.5);
        end
    end
    hold off
    
    subplot(2,2,2);
    set(gca,'FontName','Times New Roman','FontSize',10.5);
    hold on
    plot(time,rotor2,'Color','k','LineWidth',1.5);
    title('Rotor2 RPM');
    xlabel('time/s');
    ylabel('RPM');
    for i = 1:length(mission_list(:,1))
        if(mission_list(i,1) ~= 1)
        line([time(mission_list(i,3)) time(mission_list(i,3))],ylim,'linestyle','--','color','r','LineWidth',1.5);
        end
    end
    hold off
    
    subplot(2,2,3);
    set(gca,'FontName','Times New Roman','FontSize',10.5);
    hold on
    plot(time,rotor3,'Color','k','LineWidth',1.5);
    title('Rotor3 RPM');
    xlabel('time/s');
    ylabel('RPM');
    for i = 1:length(mission_list(:,1))
        if(mission_list(i,1) ~= 1)
        line([time(mission_list(i,3)) time(mission_list(i,3))],ylim,'linestyle','--','color','r','LineWidth',1.5);
        end
    end
    hold off
    
    subplot(2,2,4);
    set(gca,'FontName','Times New Roman','FontSize',10.5);
    hold on
    plot(time,rotor4,'Color','k','LineWidth',1.5);
    title('Rotor4 RPM');
    xlabel('time/s');
    ylabel('RPM');
    for i = 1:length(mission_list(:,1))
        if(mission_list(i,1) ~= 1)
        line([time(mission_list(i,3)) time(mission_list(i,3))],ylim,'linestyle','--','color','r','LineWidth',1.5);
        end
    end
    hold off
    
    figure('Name','Tilt Angle');
    tilt1 = rad2deg(out.Result_Real_Rotor(time_start:mission_list(end,3),5));
    tilt2 = rad2deg(out.Result_Real_Rotor(time_start:mission_list(end,3),6));
    
    subplot(2,1,1);
    set(gca,'FontName','Times New Roman','FontSize',10.5);
    hold on
    plot(time,tilt1,'Color','k','LineWidth',1.5);
    title('Tilt Angle1');
    xlabel('time/s');
    ylabel('Tilt Angle/°');
    for i = 1:length(mission_list(:,1))
        if(mission_list(i,1) ~= 1)
        line([time(mission_list(i,3)) time(mission_list(i,3))],ylim,'linestyle','--','color','r','LineWidth',1.5);
        end
    end
    hold off
    
    subplot(2,1,2);
    set(gca,'FontName','Times New Roman','FontSize',10.5);
    hold on
    plot(time,tilt2,'Color','k','LineWidth',1.5);
    title('Tilt Angle2');
    xlabel('time/s');
    ylabel('Tilt Angle/°');
    for i = 1:length(mission_list(:,1))
        if(mission_list(i,1) ~= 1)
        line([time(mission_list(i,3)) time(mission_list(i,3))],ylim,'linestyle','--','color','r','LineWidth',1.5);
        end
    end
    hold off
end

%% Control Surface
if plotfigure.controlsurface == 1
    figure('Name','Control Surface')
    aileron = rad2deg(out.Result_CtrlSurfaces2(time_start:mission_list(end,3),2));
    elevator = rad2deg(out.Result_CtrlSurfaces2(time_start:mission_list(end,3),1));
    rudder = rad2deg(out.Result_CtrlSurfaces2(time_start:mission_list(end,3),3));
    
    subplot(3,1,1);
    set(gca,'FontName','Times New Roman','FontSize',10.5);
    hold on
    plot(time,aileron,'Color','k','LineWidth',1.5);
    title('Aileron');
    xlabel('time/s');
    ylabel('Aileron/°');
    for i = 1:length(mission_list(:,1))
        if(mission_list(i,1) ~= 1)
        line([time(mission_list(i,3)) time(mission_list(i,3))],ylim,'linestyle','--','color','r','LineWidth',1.5);
        end
    end
    hold off
    
    subplot(3,1,2);
    set(gca,'FontName','Times New Roman','FontSize',10.5);
    hold on
    plot(time,elevator,'Color','k','LineWidth',1.5);
    title('Elevator');
    xlabel('time/s');
    ylabel('Elevator/°');
    for i = 1:length(mission_list(:,1))
        if(mission_list(i,1) ~= 1)
        line([time(mission_list(i,3)) time(mission_list(i,3))],ylim,'linestyle','--','color','r','LineWidth',1.5);
        end
    end
    hold off
    
    subplot(3,1,3);
    set(gca,'FontName','Times New Roman','FontSize',10.5);
    hold on
    plot(time,rudder,'Color','k','LineWidth',1.5);
    title('Rudder');
    xlabel('time/s');
    ylabel('Rudder/°');
    for i = 1:length(mission_list(:,1))
        if(mission_list(i,1) ~= 1)
        line([time(mission_list(i,3)) time(mission_list(i,3))],ylim,'linestyle','--','color','r','LineWidth',1.5);
        end
    end
    hold off
end

%% Attitude
if plotfigure.attitude == 1
    figure('Name','Attitude');
    roll = rad2deg(out.Result_Euler(time_start:mission_list(end,3),1));
    pitch = rad2deg(out.Result_Euler(time_start:mission_list(end,3),2));
    heading = rad2deg(out.Result_Euler(time_start:mission_list(end,3),3));
    
    subplot(3,1,1);
    set(gca,'FontName','Times New Roman','FontSize',10.5);
    hold on
    plot(time,roll,'Color','k','LineWidth',1.5);
    title('Roll');
    xlabel('time/s');
    ylabel('Roll/°');
    for i = 1:length(mission_list(:,1))
        if(mission_list(i,1) ~= 1)
        line([time(mission_list(i,3)) time(mission_list(i,3))],ylim,'linestyle','--','color','r','LineWidth',1.5);
        end
    end
    hold off
    
    subplot(3,1,2);
    set(gca,'FontName','Times New Roman','FontSize',10.5);
    hold on
    plot(time,pitch,'Color','k','LineWidth',1.5);
    title('Pitch');
    xlabel('time/s');
    ylabel('Pitch/°');
    for i = 1:length(mission_list(:,1))
        if(mission_list(i,1) ~= 1)
        line([time(mission_list(i,3)) time(mission_list(i,3))],ylim,'linestyle','--','color','r','LineWidth',1.5);
        end
    end
    hold off
    
    subplot(3,1,3);
    set(gca,'FontName','Times New Roman','FontSize',10.5);
    hold on
    plot(time,heading,'Color','k','LineWidth',1.5);
    title('Heading');
    xlabel('time/s');
    ylabel('Heading/°');
    for i = 1:length(mission_list(:,1))
        if(mission_list(i,1) ~= 1)
        line([time(mission_list(i,3)) time(mission_list(i,3))],ylim,'linestyle','--','color','r','LineWidth',1.5);
        end
    end
    hold off
end