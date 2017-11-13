/*
 * Ensuite, nous avons besoin d'une classe Camera3D - c'est très similaire à Transform3D, mais c'est beaucoup plus simple.
 * Ce n'est pas que nous ayons besoin directement d'une telle classe, mais ce serait bien de ne pas effectuer de calculs supplémentaires,
 * inutiles comme inverser notre matrice.L'interface sera très similaire à Transform3D,
 * seulement nous ne prendrons pas en charge l'échelle (ce n'est pas une opération courante de l'appareil photo).
*/
#ifndef CAMERA3D_H
#define CAMERA3D_H


#include "transform3d.h"

class Camera3D
{
public:

  // Constantes
  static const QVector3D LocalForward;
  static const QVector3D LocalUp;
  static const QVector3D LocalRight;

  // Constructeurs
  Camera3D();

  // Transforme par (Ajout/Echelle)
  void translate(const QVector3D &dt);
  void translate(float dx, float dy, float dz);
  void rotate(const QQuaternion &dr);
  void rotate(float angle, const QVector3D &axis);
  void rotate(float angle, float ax, float ay, float az);

  // Transforme en (Setters)
  void setTranslation(const QVector3D &t);
  void setTranslation(float x, float y, float z);
  void setRotation(const QQuaternion &r);
  void setRotation(float angle, const QVector3D &axis);
  void setRotation(float angle, float ax, float ay, float az);

  // Accesseurs
  const QVector3D& translation() const;
  const QQuaternion& rotation() const;
  const QMatrix4x4& toMatrix();

  // Requetes
  QVector3D forward() const;
  QVector3D right() const;
  QVector3D up() const;

private:
  bool m_dirty;
  QVector3D m_translation;
  QQuaternion m_rotation;
  QMatrix4x4 m_world;

#ifndef QT_NO_DATASTREAM
  friend QDataStream &operator<<(QDataStream &out, const Camera3D &transform);
  friend QDataStream &operator>>(QDataStream &in, Camera3D &transform);
#endif
};

Q_DECLARE_TYPEINFO(Camera3D, Q_MOVABLE_TYPE);

// Constructeurs
inline Camera3D::Camera3D() : m_dirty(true) {}

// Transforme par (Ajout/Echelle)
inline void Camera3D::translate(float dx, float dy,float dz) { translate(QVector3D(dx, dy, dz)); }
inline void Camera3D::rotate(float angle, const QVector3D &axis) { rotate(QQuaternion::fromAxisAndAngle(axis, angle)); }
inline void Camera3D::rotate(float angle, float ax, float ay,float az) { rotate(QQuaternion::fromAxisAndAngle(ax, ay, az, angle)); }

// Transforme en (Setters)
inline void Camera3D::setTranslation(float x, float y, float z) { setTranslation(QVector3D(x, y, z)); }
inline void Camera3D::setRotation(float angle, const QVector3D &axis) { setRotation(QQuaternion::fromAxisAndAngle(axis, angle)); }
inline void Camera3D::setRotation(float angle, float ax, float ay, float az) { setRotation(QQuaternion::fromAxisAndAngle(ax, ay, az, angle)); }

// Accesseurs
inline const QVector3D& Camera3D::translation() const { return m_translation; }
inline const QQuaternion& Camera3D::rotation() const { return m_rotation; }

// Qt Streams
#ifndef QT_NO_DEBUG_STREAM
QDebug operator<<(QDebug dbg, const Camera3D &transform);
#endif

#ifndef QT_NO_DATASTREAM
QDataStream &operator<<(QDataStream &out, const Camera3D &transform);
QDataStream &operator>>(QDataStream &in, Camera3D &transform);
#endif

#endif // CAMERA3D_H
