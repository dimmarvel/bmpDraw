#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <memory>

class Image {
public:
    virtual bool load(const std::string& fileName) = 0;
    virtual void display() const = 0;
    virtual ~Image() = default;
};

class SDLImage : public Image {
private:
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    SDL_Texture* texture = nullptr;

public:
    bool load(const std::string& fileName) override;
    void display() const override;
    ~SDLImage();
};

class ImageFactory {
public:
    static std::unique_ptr<Image> createImage() {
        return std::make_unique<SDLImage>();
    }
};