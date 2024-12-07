#include <Geode/Geode.hpp>
#include <Geode/modify/ButtonSprite.hpp>
#include <Geode/modify/CCMenuItemSpriteExtra.hpp>
#include <Geode/modify/CCMenu.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/loader/Mod.hpp>
#include <cstdlib> // For std::system

using namespace geode::prelude;

// Modify the MenuLayer class to replace the "More Games" button
class $modify(MyAwesomeModification, MenuLayer) {
    // Function to handle the button click
    void onMyButton(CCObject* target) {
        // Open the URL in the default browser
        std::system("open https://singdev.wixsite.com/sing-developments");
    }

    // Function to initialize the menu layer
    bool init() {
        if (!MenuLayer::init()) return false;

        // Create the custom button sprite with the text "Sing Developments"
        auto spr = ButtonSprite::create("Sing Developments");

        // Create the menu item with the custom button sprite
        auto btn = CCMenuItemSpriteExtra::create(
            spr, nullptr, this,
            menu_selector(MyAwesomeModification::onMyButton)
        );

        // Replace the "More Games" button in the menu
        auto menu = CCMenu::create();
        menu->addChild(btn);
        menu->setPosition(253, 80); // Set the position of the menu
        this->addChild(menu);

        return true;
    }
};
