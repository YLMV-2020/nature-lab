#include "pch.h"

#include"transformation.h"

#include<cmath>
#include<iostream>

transformation::transformation() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            m_a[i][j] = 0.0;
        }
    }
}

void transformation::to_opengl(float* val) {
    val[0] = m_a[0][0]; val[4] = m_a[0][1]; val[8] = m_a[0][2]; val[12] = m_a[0][3];
    val[1] = m_a[1][0]; val[5] = m_a[1][1]; val[9] = m_a[1][2]; val[13] = m_a[1][3];
    val[2] = m_a[2][0]; val[6] = m_a[2][1]; val[10] = m_a[2][2]; val[14] = m_a[2][3];
    val[3] = m_a[3][0]; val[7] = m_a[3][1]; val[11] = m_a[3][2]; val[15] = m_a[3][3];
}

void transformation::from_opengl(float* val) {
    m_a[0][0] = val[0]; m_a[0][1] = val[4]; m_a[0][2] = val[8]; m_a[0][3] = val[12];
    m_a[1][0] = val[1]; m_a[1][1] = val[5]; m_a[1][2] = val[9]; m_a[1][3] = val[13];
    m_a[2][0] = val[2]; m_a[2][1] = val[6]; m_a[2][2] = val[10]; m_a[2][3] = val[14];
    m_a[3][0] = val[3]; m_a[3][1] = val[7]; m_a[3][2] = val[11]; m_a[3][3] = val[15];
}





void transformation::get_right_up_forward_position(float* r, float* u, float* f, float* p) {
    r[0] = m_a[0][0]; u[0] = m_a[0][1]; f[0] = m_a[0][2]; p[0] = m_a[0][3];
    r[1] = m_a[1][0]; u[1] = m_a[1][1]; f[1] = m_a[1][2]; p[1] = m_a[1][3];
    r[2] = m_a[2][0]; u[2] = m_a[2][1]; f[2] = m_a[2][2]; p[2] = m_a[2][3];
}

float& transformation::operator()(int r, int c) {
    return m_a[r][c];
}

void transformation::transform_homogeneous(float* pin, float* pout) {
    float w = m_a[3][0] * pin[0] + m_a[3][1] * pin[1] + m_a[3][2] * pin[2] + m_a[3][3] * pin[3];
    pout[0] = (m_a[0][0] * pin[0] + m_a[0][1] * pin[1] + m_a[0][2] * pin[2] + m_a[0][3] * pin[3]) / w;
    pout[1] = (m_a[1][0] * pin[0] + m_a[1][1] * pin[1] + m_a[1][2] * pin[2] + m_a[1][3] * pin[3]) / w;
    pout[2] = (m_a[2][0] * pin[0] + m_a[2][1] * pin[1] + m_a[2][2] * pin[2] + m_a[2][3] * pin[3]) / w;
    pout[3] = 1.0;
}

void transformation::transform_point(float* pin, float* pout) {
    float w = m_a[3][0] * pin[0] + m_a[3][1] * pin[1] + m_a[3][2] * pin[2] + m_a[3][3];
    pout[0] = (m_a[0][0] * pin[0] + m_a[0][1] * pin[1] + m_a[0][2] * pin[2] + m_a[0][3]) / w;
    pout[1] = (m_a[1][0] * pin[0] + m_a[1][1] * pin[1] + m_a[1][2] * pin[2] + m_a[1][3]) / w;
    pout[2] = (m_a[2][0] * pin[0] + m_a[2][1] * pin[1] + m_a[2][2] * pin[2] + m_a[2][3]) / w;
}

void transformation::transform_vector(float* vin, float* vout) {
    vout[0] = (m_a[0][0] * vin[0] + m_a[0][1] * vin[1] + m_a[0][2] * vin[2]);
    vout[1] = (m_a[1][0] * vin[0] + m_a[1][1] * vin[1] + m_a[1][2] * vin[2]);
    vout[2] = (m_a[2][0] * vin[0] + m_a[2][1] * vin[1] + m_a[2][2] * vin[2]);
}

transformation transformation::transpose() {
    transformation tmp;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            tmp(i, j) = (*this)(i, j);
        }
    }
    return tmp;
}

transformation transformation::operator*(transformation in) {
    transformation tmp;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            tmp(i, j) = 0.0;
            for (int k = 0; k < 4; k++) {
                tmp(i, j) += (*this)(i, k) * in(k, j);
            }
        }
    }
    return tmp;
}

transformation transformation::inverse() {
    transformation tmp;

    // first copy to a flat layout
    float m[16];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            m[i + j * 4] = m_a[i][j];
        }
    }
    // now invert, using code directly cribbed from Rodolphe Vaillant's homepage: http://www.irit.fr/~Rodolphe.Vaillant/?e=7
    float inv[16], det;
    inv[0] = m[5] * m[10] * m[15] - m[5] * m[11] * m[14] - m[9] * m[6] * m[15] + m[9] * m[7] * m[14] + m[13] * m[6] * m[11] - m[13] * m[7] * m[10];
    inv[4] = -m[4] * m[10] * m[15] + m[4] * m[11] * m[14] + m[8] * m[6] * m[15] - m[8] * m[7] * m[14] - m[12] * m[6] * m[11] + m[12] * m[7] * m[10];
    inv[8] = m[4] * m[9] * m[15] - m[4] * m[11] * m[13] - m[8] * m[5] * m[15] + m[8] * m[7] * m[13] + m[12] * m[5] * m[11] - m[12] * m[7] * m[9];
    inv[12] = -m[4] * m[9] * m[14] + m[4] * m[10] * m[13] + m[8] * m[5] * m[14] - m[8] * m[6] * m[13] - m[12] * m[5] * m[10] + m[12] * m[6] * m[9];
    inv[1] = -m[1] * m[10] * m[15] + m[1] * m[11] * m[14] + m[9] * m[2] * m[15] - m[9] * m[3] * m[14] - m[13] * m[2] * m[11] + m[13] * m[3] * m[10];
    inv[5] = m[0] * m[10] * m[15] - m[0] * m[11] * m[14] - m[8] * m[2] * m[15] + m[8] * m[3] * m[14] + m[12] * m[2] * m[11] - m[12] * m[3] * m[10];
    inv[9] = -m[0] * m[9] * m[15] + m[0] * m[11] * m[13] + m[8] * m[1] * m[15] - m[8] * m[3] * m[13] - m[12] * m[1] * m[11] + m[12] * m[3] * m[9];
    inv[13] = m[0] * m[9] * m[14] - m[0] * m[10] * m[13] - m[8] * m[1] * m[14] + m[8] * m[2] * m[13] + m[12] * m[1] * m[10] - m[12] * m[2] * m[9];
    inv[2] = m[1] * m[6] * m[15] - m[1] * m[7] * m[14] - m[5] * m[2] * m[15] + m[5] * m[3] * m[14] + m[13] * m[2] * m[7] - m[13] * m[3] * m[6];
    inv[6] = -m[0] * m[6] * m[15] + m[0] * m[7] * m[14] + m[4] * m[2] * m[15] - m[4] * m[3] * m[14] - m[12] * m[2] * m[7] + m[12] * m[3] * m[6];
    inv[10] = m[0] * m[5] * m[15] - m[0] * m[7] * m[13] - m[4] * m[1] * m[15] + m[4] * m[3] * m[13] + m[12] * m[1] * m[7] - m[12] * m[3] * m[5];
    inv[14] = -m[0] * m[5] * m[14] + m[0] * m[6] * m[13] + m[4] * m[1] * m[14] - m[4] * m[2] * m[13] - m[12] * m[1] * m[6] + m[12] * m[2] * m[5];
    inv[3] = -m[1] * m[6] * m[11] + m[1] * m[7] * m[10] + m[5] * m[2] * m[11] - m[5] * m[3] * m[10] - m[9] * m[2] * m[7] + m[9] * m[3] * m[6];
    inv[7] = m[0] * m[6] * m[11] - m[0] * m[7] * m[10] - m[4] * m[2] * m[11] + m[4] * m[3] * m[10] + m[8] * m[2] * m[7] - m[8] * m[3] * m[6];
    inv[11] = -m[0] * m[5] * m[11] + m[0] * m[7] * m[9] + m[4] * m[1] * m[11] - m[4] * m[3] * m[9] - m[8] * m[1] * m[7] + m[8] * m[3] * m[5];
    inv[15] = m[0] * m[5] * m[10] - m[0] * m[6] * m[9] - m[4] * m[1] * m[10] + m[4] * m[2] * m[9] + m[8] * m[1] * m[6] - m[8] * m[2] * m[5];

    det = m[0] * inv[0] + m[1] * inv[4] + m[2] * inv[8] + m[3] * inv[12];

    // error checking??? Nope.
    //if(det == 0)
    //    return false;

    det = 1.0 / det;

    // copy from flat layout to returned inverse
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            tmp(i, j) = inv[i + j * 4] * det;
        }
    }

    return tmp;
}

transformation transformation::zero() {
    transformation tmp;
    tmp(0, 0) = tmp(0, 1) = tmp(0, 2) = tmp(0, 3) = 0.0;
    tmp(1, 0) = tmp(1, 1) = tmp(1, 2) = tmp(1, 3) = 0.0;
    tmp(2, 0) = tmp(2, 1) = tmp(2, 2) = tmp(2, 3) = 0.0;
    tmp(3, 0) = tmp(3, 1) = tmp(3, 2) = tmp(3, 3) = 0.0;
    return tmp;
}

transformation transformation::identity() {
    transformation tmp;
    tmp(0, 0) = tmp(1, 1) = tmp(2, 2) = tmp(3, 3) = 1.0;
    return tmp;
}

transformation transformation::rotate_x(float theta) {
    float s = sin(theta);
    float c = cos(theta);
    transformation tmp;
    tmp(0, 0) = tmp(1, 1) = tmp(2, 2) = tmp(3, 3) = 1.0;
    tmp(1, 1) = c; tmp(1, 2) = -s;
    tmp(2, 1) = s; tmp(2, 2) = c;
    return tmp;
}

transformation transformation::rotate_y(float theta) {
    float s = sin(theta);
    float c = cos(theta);
    transformation tmp;
    tmp(0, 0) = tmp(1, 1) = tmp(2, 2) = tmp(3, 3) = 1.0;
    tmp(0, 0) = c; tmp(0, 2) = s;
    tmp(2, 0) = -s; tmp(2, 2) = c;
    return tmp;
}

transformation transformation::rotate_z(float theta) {
    float s = sin(theta);
    float c = cos(theta);
    transformation tmp;
    tmp(0, 0) = tmp(1, 1) = tmp(2, 2) = tmp(3, 3) = 1.0;
    tmp(0, 0) = c; tmp(0, 1) = -s;
    tmp(1, 0) = s; tmp(1, 1) = c;
    return tmp;
}

transformation transformation::scale(float x, float y, float z) {
    transformation tmp;
    tmp(0, 0) = x;
    tmp(1, 1) = y;
    tmp(2, 2) = z;
    tmp(3, 3) = 1.0;
    return tmp;
}

transformation transformation::translate(float x, float y, float z) {
    transformation tmp;
    tmp(0, 0) = tmp(1, 1) = tmp(2, 2) = tmp(3, 3) = 1.0;
    tmp(0, 3) = x;
    tmp(1, 3) = y;
    tmp(2, 3) = z;
    return tmp;
}

transformation transformation::rotate_axis(float theta, float x, float y, float z) {
    float qx, qy, qz, qw;
    float L = sqrt(x * x + y * y + z * z);
    float c = cos(theta / 2.0), s = sin(theta / 2.0);
    qx = s * x / L;
    qy = s * y / L;
    qz = s * z / L;
    qw = c;
    transformation tmp;
    tmp(0, 0) = 1.0 - 2.0 * (qy * qy + qz * qz); tmp(1, 0) = 2.0 * (qx * qy + qw * qz);     tmp(2, 0) = 2.0 * (qx * qz - qw * qy);     tmp(3, 0) = 0.0;
    tmp(0, 1) = 2.0 * (qx * qy - qw * qz);     tmp(1, 1) = 1.0 - 2.0 * (qx * qx + qz * qz); tmp(2, 1) = 2.0 * (qy * qz + qw * qx);     tmp(3, 1) = 0.0;
    tmp(0, 2) = 2.0 * (qx * qz + qw * qy);     tmp(1, 2) = 2.0 * (qy * qz - qw * qx);     tmp(2, 2) = 1.0 - 2.0 * (qx * qx + qy * qy); tmp(3, 2) = 0.0;
    tmp(0, 3) = 0.0;                   tmp(1, 3) = 0.0;                   tmp(2, 3) = 0.0;                tmp(3, 3) = 1.0;
    return tmp;
}

transformation transformation::glIdentity() {
    return transformation::identity();
}

transformation transformation::glScale(float x, float y, float z) {
    return transformation::scale(x, y, z);
}

transformation transformation::glTranslate(float x, float y, float z) {
    return transformation::translate(x, y, z);
}

transformation transformation::glRotate(float theta, float x, float y, float z) {
    return transformation::rotate_axis(theta * Math:: PI / 180.0, x, y, z);
}

transformation transformation::glOrtho(float left, float right, float bottom, float top, float nearVal, float farVal) {
    transformation tmp;
    float tx, ty, tz;
    tx = -(right + left) / (right - left);
    ty = -(top + bottom) / (top - bottom);
    tz = -(farVal + nearVal) / (farVal - nearVal);
    tmp(0, 0) = 2.0 / (right - left);
    tmp(1, 1) = 2.0 / (top - bottom);
    tmp(2, 2) = -2.0 / (farVal - nearVal);
    tmp(3, 3) = 1.0;
    tmp(0, 3) = tx;
    tmp(1, 3) = ty;
    tmp(2, 3) = tz;
    return tmp;
}


transformation transformation::glFrustum(float left, float right, float bottom, float top, float nearVal, float farVal) {
    float A, B, C, D;
    transformation tmp = transformation::identity();
    tmp(0, 0) = 2.0 * nearVal / (right - left);
    tmp(1, 1) = 2.0 * nearVal / (top - bottom);
    tmp(3, 2) = -1.0;
    tmp(3, 3) = 0.0;

    A = (right + left) / (right - left);
    B = (top + bottom) / (top - bottom);
    C = -(farVal + nearVal) / (farVal - nearVal);
    D = -(2 * farVal * nearVal) / (farVal - nearVal);

    tmp(0, 2) = A;
    tmp(1, 2) = B;
    tmp(2, 2) = C;
    tmp(2, 3) = D;
    return tmp;
}

void transformation::gluProject(float objX, float objY, float objZ, float* model, float* proj, int* view, float* winX, float* winY, float* winZ) {
    transformation M, P, tmp;
    float pout[4], pin[] = { objX, objY, objZ, 1.0 };
    M.from_opengl(model);
    P.from_opengl(proj);
    tmp = P * M;
    tmp.transform_homogeneous(pin, pout);
    *winX = view[0] + 0.5 * float(view[2]) * (pout[0] + 1.0);
    *winY = view[1] + 0.5 * float(view[3]) * (pout[1] + 1.0);
    *winZ = 0.5 * (pout[2] + 1.0);
}

void transformation::gluUnProject(float winX, float winY, float winZ, float* model, float* proj, int* view, float* objX, float* objY, float* objZ) {
    transformation M, P, tmp;
    float pout[4], pin[] = { 2.0 * (winX - float(view[0])) / float(view[2]) - 1.0, 2.0 * (winY - float(view[1])) / float(view[3]) - 1.0, 2.0 * winZ - 1.0, 1.0 };
    M.from_opengl(model);
    P.from_opengl(proj);
    tmp = (P * M).inverse();
    tmp.transform_homogeneous(pin, pout);
    *objX = pout[0];
    *objY = pout[1];
    *objZ = pout[2];
}

transformation transformation::gluLookAt(float eyeX, float eyeY, float eyeZ, float centerX, float centerY, float centerZ, float upX, float upY, float upZ) {
    transformation tmp;
    float u[] = { upX, upY, upZ };
    float f[] = { centerX - eyeX, centerY - eyeY, centerZ - eyeZ };
    float L = sqrt(f[0] * f[0] + f[1] * f[1] + f[2] * f[2]);
    f[0] /= L; f[1] /= L; f[2] /= L;
    float r[] = { f[1] * u[2] - f[2] * u[1], f[2] * u[0] - f[0] * u[2], f[0] * u[1] - f[1] * u[0] };
    L = sqrt(r[0] * r[0] + r[1] * r[1] + r[2] * r[2]);
    r[0] /= L; r[1] /= L; r[2] /= L;
    u[0] = r[1] * f[2] - r[2] * f[1];
    u[1] = r[2] * f[0] - r[0] * f[2];
    u[2] = r[0] * f[1] - r[1] * f[0];
    tmp(0, 0) = r[0]; tmp(0, 1) = r[1]; tmp(0, 2) = r[2];
    tmp(1, 0) = u[0]; tmp(1, 1) = u[1]; tmp(1, 2) = u[2];
    tmp(2, 0) = -f[0]; tmp(2, 1) = -f[1]; tmp(2, 2) = -f[2];
    tmp(3, 3) = 1.0;
    return tmp * transformation::glTranslate(-eyeX, -eyeY, -eyeZ);
}

transformation transformation::gluPerspective(float fovy, float aspect, float zNear, float zFar) {
    transformation tmp;
    float f = 1.0 / tan(fovy * Math::PI / 360.0);
    tmp(0, 0) = f / aspect;
    tmp(1, 1) = f;
    tmp(2, 2) = (zFar + zNear) / (zNear - zFar); tmp(2, 3) = 2.0 * zFar * zNear / (zNear - zFar);
    tmp(3, 2) = -1.0;
    return tmp;
}

