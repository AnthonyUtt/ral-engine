#include <ral-core.h>

class App : public RALengine::Application{
public:
    App()
    {
    }

    ~App()
    {
    }
};

RALengine::Application* RALengine::CreateApplication()
{
    return new App();
}