#pragma once
#pragma comment(lib,"dwmapi.lib")

#include <dwmapi.h>
#include <QDialog>
#include <QWidget>
#include <windowsx.h>
#include <WinUser.h>

class FramelessWindow : public QWidget {
    Q_OBJECT

    public:
        explicit FramelessWindow(QWidget* parent = nullptr);

    protected:
        bool nativeEvent(const QByteArray& eventType, void* message, qint64* result) override;

        void mousePressEvent(QMouseEvent* event) override;

        void mouseMoveEvent(QMouseEvent* event) override;

        void mouseReleaseEvent(QMouseEvent* event) override;

    private:
        int adjustResizeWindow(const QPoint& pos);

        bool m_dragging {false};
        QPoint m_dragPos;
};
