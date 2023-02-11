#ifndef HOMEBUTTONS_STATE_H
#define HOMEBUTTONS_STATE_H

#include <Preferences.h>
#include "buttons.h"

class State {
public:
  // #### FACTORY ####
  String serial_number = "";  // len = 8
  String random_id = "";      // len = 6
  String model_name = "";     // 1 < len < 20
  String model_id = "";       // len = 2
  String hw_version = "";     // len = 3
  String unique_id = "";      // len = 20

  // #### USER ####
  // network
  String mqtt_server = "";
  String mqtt_user = "";
  String mqtt_password = "";
  int32_t mqtt_port = 0;
  String base_topic = "";
  String discovery_prefix = "";

  // personalization
  String device_name = "";
  String btn_1_label = "";
  String btn_2_label = "";
  String btn_3_label = "";
  String btn_4_label = "";
  String btn_5_label = "";
  String btn_6_label = "";
  uint16_t sensor_interval = 0;  // minutes

  // #### PERSISTED VARS ####
  bool low_batt_mode = false;
  bool wifi_done = false;
  bool setup_done = false;
  String last_sw_ver = "";
  bool user_awake_mode = false;

  // persisted flags
  bool wifi_quick_connect = false;
  bool charge_complete_showing = false;
  bool info_screen_showing = false;
  bool check_connection = false;
  uint8_t failed_connections = 0;
  bool restart_to_wifi_setup = false;
  bool restart_to_setup = false;
  bool send_discovery_config = false;
  bool silent_restart = false;

  // #### NOT SAVED ####
  // topics
  String t_common = "";
  String t_cmd = "";
  String t_btn_press[6];
  String t_btn_press_double[6];
  String t_btn_press_triple[6];
  String t_btn_press_quad[6];
  String t_temperature = "";
  String t_humidity = "";
  String t_battery = "";
  String t_sensor_interval_cmd = "";
  String t_sensor_interval_state = "";
  String t_btn_label_state[6];
  String t_btn_label_cmd[6];
  String t_awake_mode_state = "";
  String t_awake_mode_cmd = "";
  String t_awake_mode_avlb = "";

  // flags
  bool display_redraw = false;
  bool awake_mode = false;

  // sensor
  float temperature = 0;
  float humidity = 0;
  uint8_t battery_pct = 0;
  bool charging = false;
  bool dc_connected = false;
  bool battery_present = false;
  bool battery_low = false;

  // network
  String ip = "";
  String ap_ssid = "";
  String ap_password = "";

  // #### END ####

  // functions
  void save_factory();
  void load_factory();
  void clear_factory();

  void save_user();
  void load_user();
  void clear_user();

  void save_persisted();
  void load_persisted();
  void clear_persisted();
  void clear_persisted_flags();

  void save_all();
  void load_all();
  void clear_all();

  String get_btn_label(uint8_t i);
  void set_btn_label(uint8_t i, String label);
  void set_topics();
  String get_button_topic(uint8_t btn_idx, Button::ButtonAction action);

private:
  Preferences preferences;
};

extern State device_state;

#endif // HOMEBUTTONS_STATE_H