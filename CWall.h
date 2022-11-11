#ifndef _CWALL_
#define _CWALL_

#include "d3dUtility.h"
#include "CSphere.h"


class CWall 
{
private:
    float m_x;
    float m_z;
    float m_width;
    float m_depth;
    float m_height;

    //float pre_center_x, pre_center_z;

    D3DXMATRIX              m_mLocal;
    D3DMATERIAL9            m_mtrl;
    ID3DXMesh* m_pBoundMesh;

    float center_x, center_y, center_z;

    void setLocalTransform(const D3DXMATRIX& mLocal);

public:

    static const float LOSS_RATIO;

    CWall(void);
    ~CWall(void);
    bool create(IDirect3DDevice9* pDevice, float ix, float iz, float iwidth, float iheight, float idepth, D3DXCOLOR color);
    void destroy(void);
    void draw(IDirect3DDevice9* pDevice, const D3DXMATRIX& mWorld);
    bool hasIntersected(CSphere& ball);
    void hitBy(CSphere& ball);
    void setPosition(float x, float y, float z);
    float getHeight(void) const;

 
};

#endif