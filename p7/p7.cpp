#include <iostream>
#include <Eigen/Core>
#include <Eigen/Geometry>

using namespace std;
int main(int argc,char **argv)
{
		//导入小萝卜1号的数据
		Eigen::Quaterniond q1(0.35,0.2,0.3,0.1);
		Eigen::Vector3d t1(0.3,0.1,0.1);


		//导入小萝卜2号的数据
		Eigen::Quaterniond q2(-0.5,0.4,-0.1,0.2);
		Eigen::Vector3d t2(-0.1,0.5,0.3);


		//导入小萝卜1号看到的观测点数据
		Eigen::Vector3d p(0.5,0,0.2);


		//导入小萝卜2号看到的观测点数据
		Eigen::Vector3d o;


		//初始化欧式变换矩阵,不能直接输出这个欧式变换矩阵，为啥呢？？
		Eigen::Isometry3d T_1cw = Eigen::Isometry3d::Identity();
		Eigen::Isometry3d T_2cw = Eigen::Isometry3d::Identity();


		//开始求解
		//归一化四元素
		q1.normalize();
		q2.normalize();

		//输出归一化后的信息
		cout << "q1 = " << endl << q1.x() << q1.y() << q1.z() << endl << q1.w() << endl;
		cout << "q2 = " << endl << q2.x() << q2.y() << q2.z() << endl << q2.w() << endl;

		//四元素转为旋转矩阵，然后与位移融合形成欧式变换矩阵
		T_1cw.rotate(q1);
		T_1cw.pretranslate(t1);

		T_2cw.rotate(q2);
		T_2cw.pretranslate(t2);

		//输出欧式变换矩阵的信息
		cout << "T_1cw:" << endl << T_1cw.matrix() << endl;
		cout << "T_2cw:" << endl << T_2cw.matrix() << endl;

		//求解o坐标
		o = T_2cw * T_1cw.inverse() * p;

		//输出o坐标
		cout << "o = " << o.transpose() << endl;

		return 0;
		
}

