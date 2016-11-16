#ifndef RENDERSETTINGSINITIALIZATIONS_H
#define RENDERSETTINGSINITIALIZATIONS_H

#include <QtGui/qsurface.h>

enum settingStatus {
    NotInitialized = -1
};

class RenderSettingsInitializations
{
public:
    RenderSettingsInitializations();

    // Setters
    void setWidth(int newWidth);
    void setHeight(int newHeight);
    void setDevicePixelRatio(qreal newDevicePixelRatio);
    void setRefreshRate(qreal newRefreshRate);

    // Getters
    int width() const;
    int height() const;
    qreal devicePixelRatio() const;
    qreal refreshRate() const;

    // Operators
    RenderSettingsInitializations& operator=( RenderSettingsInitializations& settings );

private:
    int m_width;
    int m_height;
    qreal m_devicePixelRatio;
    qreal m_refreshRate;
};

#endif // RENDERSETTINGSINITIALIZATIONS_H
