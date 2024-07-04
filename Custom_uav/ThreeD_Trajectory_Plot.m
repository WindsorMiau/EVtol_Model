tf = 1:19245;
tf = tf .* 0.005;
x = out.Result_Xe(1:19245,1);
y = out.Result_Xe(1:19245,2);
z = -out.Result_Xe(1:19245,3);


figure;
plot3(x,y,z,'b-','LineWidth',2);
grid on
xlabel('N Position(m)','FontName','Times New Roman','FontSize',20);
ylabel('E Position(m)','FontName','Times New Roman','FontSize',20);
zlabel('Altitude(m)','FontName','Times New Roman','FontSize',20);
title('3D Trajectory','FontName','Times New Roman','FontSize',20);