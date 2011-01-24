/*
**  Xbox360 USB Gamepad Userspace Driver
**  Copyright (C) 2010 Ingo Ruhnke <grumbel@gmx.de>
**
**  This program is free software: you can redistribute it and/or modify
**  it under the terms of the GNU General Public License as published by
**  the Free Software Foundation, either version 3 of the License, or
**  (at your option) any later version.
**
**  This program is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**  GNU General Public License for more details.
**
**  You should have received a copy of the GNU General Public License
**  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef HEADER_XBOXDRV_UI_EVENT_HPP
#define HEADER_XBOXDRV_UI_EVENT_HPP

#include <boost/lexical_cast.hpp>
#include <stdint.h>

enum {
  DEVICEID_INVALID  = static_cast<uint16_t>(-4),
  DEVICEID_KEYBOARD = static_cast<uint16_t>(-3),
  DEVICEID_MOUSE    = static_cast<uint16_t>(-2),
  DEVICEID_AUTO     = static_cast<uint16_t>(-1),
  DEVICEID_JOYSTICK =  0
};

enum {
  SLOTID_AUTO = static_cast<uint16_t>(-1)
};

class UIEvent 
{
public:
  static UIEvent create(int device_id, int type, int code);
  static UIEvent invalid();

public:
  void resolve_device_id(int slot, bool extra_devices);
  bool is_valid() const;
  bool operator<(const UIEvent& rhs)  const;

  int type;
  int code;

  uint32_t get_device_id() const;

private:
  uint16_t m_slot_id;
  uint16_t m_device_id;
  bool m_device_id_resolved;
};

/** Takes "1-BTN_A" splits it into "1", "BTN_A" */
void split_event_name(const std::string& str, std::string* event_str, int* device_id);

#endif

/* EOF */