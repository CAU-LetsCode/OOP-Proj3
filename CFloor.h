#ifndef _CFloor_
#define _CFloor_

#include "d3dUtility.h"
#include "CSphere.h"


class CFloor
{
protected:
    float m_x;
    float m_z;
    float m_width;
    float m_depth;
    float m_height;

    int type; // 0:top, 1:bottom, 2: right, 3:left

    //float pre_center_x, pre_center_z;

    D3DXMATRIX              m_mLocal;
    D3DMATERIAL9            m_mtrl;
    ID3DXMesh* m_pBoundMesh;

    float center_x, center_y, center_z;

    void setLocalTransform(const D3DXMATRIX& mLocal);

public:

    static const float LOSS_RATIO;

    CFloor(void);
    CFloor(float iwidth, float iheight, float idepth, D3DXCOLOR color);

    ~CFloor(void);
    bool create(IDirect3DDevice9* pDevice, float ix, float iz, float iwidth, float iheight, float idepth, D3DXCOLOR color);
    void destroy(void);
    void draw(IDirect3DDevice9* pDevice, const D3DXMATRIX& mWorld);

    void setPosition(float x, float y, float z);
    float getHeight(void) const;
    void setType(int type);


    D3DXVECTOR3 getPosition() const; // 객체의 중심 위치를 반환
    D3DXMATRIX getLocalTransform() const; // 객체의 Local Transform Matrix 반환
};

#endif