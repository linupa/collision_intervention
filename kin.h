#ifndef __KIN_H__
#define __KIN_H__
#include <iostream>
#include <Eigen/Eigen>

using namespace Eigen;

class Link;

class Links
{
public:
	Link *node;
	Links(const Link &link);
	~Links(void);
};

class Link
{
public:
	VectorXd	com;
	VectorXd	trans;
	MatrixXd	rot;	
	MatrixXd	rot2;
	double		mass;
	int			axis;
	Link		*parent;
	bool		dirty;

				Link(void);
	VectorXd	getGlobal(const VectorXd &local);
	void		setRot(VectorXd quat);
	void		setRot(VectorXd axis, double deg);
	Link 		&operator=(const Link &src);
	double		setTheta(double theta_);
	double		getTheta(void);

private:
	double		theta;
};



#endif // __KIN_H__
