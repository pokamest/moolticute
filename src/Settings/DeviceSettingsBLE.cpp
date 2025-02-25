#include "DeviceSettingsBLE.h"

DeviceSettingsBLE::DefaultValues DeviceSettingsBLE::m_bleDefaultValues =
    {
        {MPParams::RANDOM_INIT_PIN_PARAM, 0},
        {MPParams::USER_INTER_TIMEOUT_PARAM, 15},
        {MPParams::PROMPT_ANIMATION_PARAM, 1}, //FLASH_SCREEN_ID
        {MPParams::BOOT_ANIMATION_PARAM, 1},
        {MPParams::DEVICE_LANGUAGE, 0},
        {MPParams::KEY_AFTER_LOGIN_SEND_PARAM, 0x09},
        {MPParams::KEY_AFTER_PASS_SEND_PARAM, 0x0A},
        {MPParams::DELAY_AFTER_KEY_ENTRY_PARAM, 15},
        {MPParams::BOOT_ANIMATION_PARAM, 1},
        {MPParams::DEVICE_LOCK_USB_DISC, 1},
        {MPParams::MINI_KNOCK_THRES_PARAM, 9},
        {MPParams::PIN_SHOWN_ON_BACK, 0},
        {MPParams::LOCK_UNLOCK_FEATURE_PARAM, 0},
        {MPParams::TUTORIAL_BOOL_PARAM, 1},
        {MPParams::PIN_SHOW_ON_ENTRY, 0},
        {MPParams::DISABLE_BLE_ON_CARD_REMOVE, 0},
        {MPParams::DISABLE_BLE_ON_LOCK, 0},
        {MPParams::NB_20MINS_TICKS_FOR_LOCK, 0},
        {MPParams::SWITCH_OFF_AFTER_USB_DISC, 0},
        {MPParams::HASH_DISPLAY_FEATURE_PARAM, 0},
        {MPParams::INFORMATION_TIME_DELAY, 30},
        {MPParams::BLUETOOTH_SHORTCUTS, 0},
        {MPParams::SCREEN_SAVER_ID, 0},
        {MPParams::DISP_TOTP_AFTER_RECALL, 0},
        {MPParams::START_LAST_ACCESSED_SERVICE, 1},
        {MPParams::SWITCH_OFF_AFTER_BT_DISC, 0},
        {MPParams::MC_SUBDOMAIN_FORCE_STATUS, 0},
        {MPParams::FAV_LAST_USED_SORTED, 0},
        {MPParams::DELAY_BEF_UNLOCK_LOGIN, 60},
        {MPParams::SCREEN_BRIGHTNESS_USB, 0x90},
        {MPParams::SCREEN_BRIGHTNESS_BAT, 0x90},
        {MPParams::LOGIN_AND_FAV_INVERTED, 0}
    };

DeviceSettingsBLE::DeviceSettingsBLE(QObject *parent)
    : DeviceSettings(parent)
{
    fillParameterMapping();
}

void DeviceSettingsBLE::resetDefaultSettings()
{
    for (DefaultValues::iterator it = m_bleDefaultValues.begin(); it != m_bleDefaultValues.end(); ++it)
    {
        updateParam(it.key(), it.value());
    }
}

void DeviceSettingsBLE::fillParameterMapping()
{
    m_paramMap.insert(MPParams::KEYBOARD_USB_LAYOUT, "keyboard_usb_layout");
    m_paramMap.insert(MPParams::KEYBOARD_BT_LAYOUT, "keyboard_bt_layout");
    m_paramMap.insert(MPParams::DEVICE_LANGUAGE, "device_language");
    m_paramMap.insert(MPParams::USER_LANGUAGE, "user_language");
    m_bleByteMapping[MPParams::RANDOM_INIT_PIN_PARAM] = RANDOM_PIN_BYTE;
    m_bleByteMapping[MPParams::USER_INTER_TIMEOUT_PARAM] = USER_INTERACTION_TIMEOUT_BYTE;
    m_bleByteMapping[MPParams::KEY_AFTER_LOGIN_SEND_PARAM] = DEFAULT_CHAR_AFTER_LOGIN;
    m_bleByteMapping[MPParams::KEY_AFTER_PASS_SEND_PARAM] = DEFAULT_CHAR_AFTER_PASS;
    m_bleByteMapping[MPParams::DELAY_AFTER_KEY_ENTRY_PARAM] = DELAY_BETWEEN_KEY_PRESS;
    m_paramMap.insert(MPParams::RESERVED_BLE, "reserved_ble");
    m_bleByteMapping[MPParams::RESERVED_BLE] = RESERVED_BYTE;
    m_paramMap.insert(MPParams::PROMPT_ANIMATION_PARAM, "prompt_animation");
    m_bleByteMapping[MPParams::PROMPT_ANIMATION_PARAM] = ANIMATION_DURING_PROMPT_BYTE;
    m_paramMap.insert(MPParams::BOOT_ANIMATION_PARAM, "bool_animation");
    m_bleByteMapping[MPParams::BOOT_ANIMATION_PARAM] = BOOT_ANIMATION_BYTE;
    m_paramMap.insert(MPParams::DEVICE_LOCK_USB_DISC, "device_lock_usb_disc");
    m_bleByteMapping[MPParams::DEVICE_LOCK_USB_DISC] = DEVICE_LOCK_USB_BYTE;
    m_bleByteMapping[MPParams::MINI_KNOCK_THRES_PARAM] = KNOCK_DET_BYTE;
    m_bleByteMapping[MPParams::LOCK_UNLOCK_FEATURE_PARAM] = UNLOCK_FEATURE_BYTE;
    m_paramMap.insert(MPParams::PIN_SHOWN_ON_BACK, "pin_shown_on_back");
    m_bleByteMapping[MPParams::PIN_SHOWN_ON_BACK] = PIN_SHOWN_ON_BACK_BYTE;
    m_paramMap.insert(MPParams::PIN_SHOW_ON_ENTRY, "pin_show_on_entry");
    m_bleByteMapping[MPParams::TUTORIAL_BOOL_PARAM] = DEVICE_TUTORIAL_BYTE;
    m_bleByteMapping[MPParams::PIN_SHOW_ON_ENTRY] = PIN_SHOW_ON_ENTRY_BYTE;
    m_paramMap.insert(MPParams::DISABLE_BLE_ON_CARD_REMOVE, "disable_ble_on_card_remove");
    m_bleByteMapping[MPParams::DISABLE_BLE_ON_CARD_REMOVE] = DISABLE_BLE_ON_CARD_REMOVE;
    m_paramMap.insert(MPParams::DISABLE_BLE_ON_LOCK, "disable_ble_on_lock");
    m_bleByteMapping[MPParams::DISABLE_BLE_ON_LOCK] = DISABLE_BLE_ON_LOCK;
    m_paramMap.insert(MPParams::NB_20MINS_TICKS_FOR_LOCK, "nb_20mins_ticks_for_lock");
    m_bleByteMapping[MPParams::NB_20MINS_TICKS_FOR_LOCK] = NB_20MINS_TICKS_FOR_LOCK;
    m_paramMap.insert(MPParams::SWITCH_OFF_AFTER_USB_DISC, "switch_off_after_usb_disc");
    m_bleByteMapping[MPParams::SWITCH_OFF_AFTER_USB_DISC] = SWITCH_OFF_AFTER_USB_DISC;
    m_bleByteMapping[MPParams::HASH_DISPLAY_FEATURE_PARAM] = HASH_DISPLAY_BYTE;
    m_paramMap.insert(MPParams::INFORMATION_TIME_DELAY, "information_time_delay");
    m_bleByteMapping[MPParams::INFORMATION_TIME_DELAY] = INFORMATION_TIME_DELAY_BYTE;
    m_paramMap.insert(MPParams::BLUETOOTH_SHORTCUTS, "bluetooth_shortcuts");
    m_bleByteMapping[MPParams::BLUETOOTH_SHORTCUTS] = BLUETOOTH_SHORTCUTS_BYTE;
    m_paramMap.insert(MPParams::SCREEN_SAVER_ID, "screen_saver_id");
    m_bleByteMapping[MPParams::SCREEN_SAVER_ID] = SCREEN_SAVER_ID_BYTE;
    m_paramMap.insert(MPParams::DISP_TOTP_AFTER_RECALL, "display_totp_after_recall");
    m_bleByteMapping[MPParams::DISP_TOTP_AFTER_RECALL] = DISP_TOTP_AFTER_RECALL;
    m_paramMap.insert(MPParams::START_LAST_ACCESSED_SERVICE, "start_last_accessed_service");
    m_bleByteMapping[MPParams::START_LAST_ACCESSED_SERVICE] = START_LAST_ACCESSED_SERVICE;
    m_paramMap.insert(MPParams::SWITCH_OFF_AFTER_BT_DISC, "switch_off_after_bt_disc");
    m_bleByteMapping[MPParams::SWITCH_OFF_AFTER_BT_DISC] = SWITCH_OFF_AFTER_BT_DISC;
    m_paramMap.insert(MPParams::MC_SUBDOMAIN_FORCE_STATUS, "mc_subdomain_force_status");
    m_bleByteMapping[MPParams::MC_SUBDOMAIN_FORCE_STATUS] = MC_SUBDOMAIN_FORCE_STATUS;
    m_paramMap.insert(MPParams::FAV_LAST_USED_SORTED, "fav_last_used_sorted");
    m_bleByteMapping[MPParams::FAV_LAST_USED_SORTED] = FAV_LAST_USED_SORTED;
    m_paramMap.insert(MPParams::DELAY_BEF_UNLOCK_LOGIN, "delay_bef_unlock_login");
    m_bleByteMapping[MPParams::DELAY_BEF_UNLOCK_LOGIN] = DELAY_BEF_UNLOCK_LOGIN;
    m_paramMap.insert(MPParams::SCREEN_BRIGHTNESS_USB, "screen_brightness_usb");
    m_bleByteMapping[MPParams::SCREEN_BRIGHTNESS_USB] = SCREEN_BRIGHTNESS_USB;
    m_paramMap.insert(MPParams::SCREEN_BRIGHTNESS_BAT, "screen_brightness_bat");
    m_bleByteMapping[MPParams::SCREEN_BRIGHTNESS_BAT] = SCREEN_BRIGHTNESS_BAT;
    m_paramMap.insert(MPParams::LOGIN_AND_FAV_INVERTED, "login_and_fav_inverted");
    m_bleByteMapping[MPParams::LOGIN_AND_FAV_INVERTED] = LOGIN_AND_FAV_INVERTED;
}

