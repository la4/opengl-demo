#include "rendersettingsinitializations.h"

RenderSettingsInitializations::RenderSettingsInitializations() : m_width(NOT_INITIALIZED),
                                                                 m_height(NOT_INITIALIZED),
                                                                 m_devicePixelRatio(NOT_INITIALIZED),
                                                                 m_refreshRate(NOT_INITIALIZED)
{
}

void RenderSettingsInitializations::setWidth( int newWidth ) {
    // Some validation might be here
    this->m_width = newWidth;
}
void RenderSettingsInitializations::setHeight( int newHeight ) {
    // Some validation might be here
    this->m_height = newHeight;
}
void RenderSettingsInitializations::setDevicePixelRatio( qreal newDevicePixelRatio ) {
    // Some validation might be here
    this->m_devicePixelRatio = newDevicePixelRatio;
}
void RenderSettingsInitializations::setRefreshRate( qreal newRefreshRate ) {
    // Some validation might be here
    this->m_refreshRate = newRefreshRate;
}

int RenderSettingsInitializations::width() const {
    return m_width;
}
int RenderSettingsInitializations::height() const {
    return m_height;
}
qreal RenderSettingsInitializations::devicePixelRatio() const {
    return m_devicePixelRatio;
}
qreal RenderSettingsInitializations::refreshRate() const {
    return m_refreshRate;
}

RenderSettingsInitializations& RenderSettingsInitializations::operator=( RenderSettingsInitializations& settings ) {
    this->m_width = settings.m_width;
    this->m_height = settings.m_height;
    this->m_devicePixelRatio = settings.m_devicePixelRatio;
    this->m_refreshRate = settings.m_refreshRate;
    return *this;
}
