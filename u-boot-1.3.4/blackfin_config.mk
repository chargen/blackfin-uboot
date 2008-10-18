#
# (C) Copyright 2000-2002
# Wolfgang Denk, DENX Software Engineering, wd@denx.de.
#
# See file CREDITS for list of people who contributed to this
# project.
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License as
# published by the Free Software Foundation; either version 2 of
# the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston,
# MA 02111-1307 USA
#

define extract_define
$(strip $(shell echo '$1' | $(CPP) -P -include $(TOPDIR)/include/configs/$(BOARD).h -I $(TOPDIR)/include - 2>/dev/null | tail -n 1))
endef

CONFIG_BFIN_CPU := $(strip $(subst ",,$(CONFIG_BFIN_CPU)))
CONFIG_BFIN_BOOT_MODE := $(strip $(subst ",,$(CONFIG_BFIN_BOOT_MODE)))
ENV_OFFSET_SIZE = $(call extract_define, $$((CFG_ENV_OFFSET)):$$((CFG_ENV_SIZE)))
ENV_IS_EMBEDDED_CUSTOM = $(call extract_define, ENV_IS_EMBEDDED_CUSTOM)

PLATFORM_RELFLAGS += -ffixed-P5 -fomit-frame-pointer
PLATFORM_CPPFLAGS += -DCONFIG_BLACKFIN

ifneq (,$(CONFIG_BFIN_CPU))
PLATFORM_RELFLAGS += -mcpu=$(CONFIG_BFIN_CPU)
endif

SYM_PREFIX = _

LDR_FLAGS += -J
LDR_FLAGS += --bmode $(subst BFIN_BOOT_,,$(CONFIG_BFIN_BOOT_MODE))
LDR_FLAGS += --use-vmas
ifneq ($(CONFIG_BFIN_BOOT_MODE),BFIN_BOOT_BYPASS)
LDR_FLAGS += --initcode $(obj)cpu/$(CPU)/initcode.o
ifneq ($(CONFIG_BFIN_BOOT_MODE),BFIN_BOOT_UART)
ifneq ($(ENV_IS_EMBEDDED_CUSTOM),ENV_IS_EMBEDDED_CUSTOM)
LDR_FLAGS += --punchit $(ENV_OFFSET_SIZE):$(obj)env-ldr.o
endif
endif
endif
ifneq (,$(findstring s,$(MAKEFLAGS)))
LDR_FLAGS += --quiet
endif
