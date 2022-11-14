#ifndef _CSPHERE_
#define _CSPHERE_

#include "d3dUtility.h"



class CSphere 
{
private:
	float					center_x, center_y, center_z;
	float                   m_radius;
	float					m_velocity_x;
	float					m_velocity_z;

	float pre_center_x, pre_center_z;

	D3DXMATRIX              m_mLocal;
	D3DMATERIAL9            m_mtrl;
	ID3DXMesh* m_pSphereMesh;

public:
	CSphere(void);
	~CSphere(void);

	bool create(IDirect3DDevice9* pDevice, D3DXCOLOR color);
	void destroy(void);
	void draw(IDirect3DDevice9* pDevice, const D3DXMATRIX& mWorld);
	bool hasIntersected(CSphere& ball);
	void hitBy(CSphere& ball);
	void ballUpdate(float timeDiff);
	double getVelocity_X();
	double getVelocity_Z();
	void setPower(double vx, double vz);
	void setCenter(float x, float y, float z);
	float getRadius(void) const;
	const D3DXMATRIX& getLocalTransform(void) const;
	void setLocalTransform(const D3DXMATRIX& mLocal);
	D3DXVECTOR3 getPosition() const;
	void adjustPosition(CSphere& ball);
	void setPosition(float x, float y, float z);
	double CSphere::getPreCenter_x() const;
	double CSphere::getPreCenter_z() const;
};

#endif