#include "diffuseobject.h"
#include <QTextureWrapMode>
#include <QAbstractTexture>

SolarSystem::DiffuseObject::DiffuseObject(Qt3DCore::QNode* parent):
    SolarObject3D(parent)
{
    materialType_ = SolarMaterials::Diffuse;
    material_ = new Qt3DExtras::QDiffuseMapMaterial();

    auto mat = qobject_cast<Qt3DExtras::QDiffuseMapMaterial*>(material_);
    Qt3DRender::QTextureWrapMode wrapMode;

    wrapMode.setX(Qt3DRender::QTextureWrapMode::WrapMode::Repeat);
    wrapMode.setY(Qt3DRender::QTextureWrapMode::WrapMode::Repeat);
    wrapMode.setZ(Qt3DRender::QTextureWrapMode::WrapMode::Repeat);

    mat->diffuse()->setWrapMode(wrapMode);
    mat->diffuse()->setGenerateMipMaps(true);
    mat->diffuse()->setMagnificationFilter(Qt3DRender::QAbstractTexture::Linear);
    mat->diffuse()->setMinificationFilter(Qt3DRender::QAbstractTexture::LinearMipMapLinear);
    mat->diffuse()->setMaximumAnisotropy(16.0f);

    mat->setShininess(10000000);
    mat->setSpecular(QColor(qRgba(0,0,0,255)));
    mat->setAmbient(QColor(qRgba(10,10,10,255)));
    mat->setTextureScale(1.0f);

    addComponent(material_);
}
