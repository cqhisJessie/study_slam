#include<iostream>
/*
 * 提取大矩阵左上角3x3矩阵，有两种方式
 * 1.直接从0-2循环遍历大矩阵的前3行和3列
 * 2.用矩阵变量.block(0,0,3,3)//从左上角00位置开始取3行3列
 */

//包含Eigen头文件
#include<Eigen/Core>
#include<Eigen/Geometry>

#define MATRIX_SIZE 30
using namespace std;

int main(int argc,char **argv)
{
		//设置输出小数点后3位
		cout.precision(3);
		Eigen::Matrix<double,MATRIX_SIZE,MATRIX_SIZE> matrix_NN = Eigen::MatrixXd::Random(MATRIX_SIZE,MATRIX_SIZE);
		//Eigen::Matrix<double,3,3> matrix_3d1 = Eigen::MatrixXd::Random(3,3);//3x3矩阵变量
		Eigen::Matrix3d matrix_3d = Eigen::Matrix3d::Random();

		/*
		//方法一：循环便利三行三列
		for(int i = 0;i < 3;i++)
		{
				for(int j = 0;j < 3;j++)
				{
						matrix_3d(i,j) = matrix_NN(i,j);
						cout << matrix_NN(i,j)<< " ";
				}
				cout << endl;
		}
		//Identity()的作用是：单位化矩阵
		matrix_3d = Eigen::Matrix3d::Identity();
		cout << "赋值后的矩阵位：" << endl ;
		cout << matrix_3d<< endl;
		*/


		cout << "------- 方法2:使用block()函数---------" << endl;
		cout << "提取出来的矩阵块为：" << endl;
		cout << matrix_NN.block(0,0,3,3) << endl;
		//matrix_3d = matrix_NN.block(0,0,3,3);
		matrix_3d = Eigen::Matrix3d::Identity();
		//cout << "赋值后的矩阵位："　<< endl;
		cout << "赋值后的矩阵为："<< endl;
		cout << matrix_3d << endl;
		return 0;



}
