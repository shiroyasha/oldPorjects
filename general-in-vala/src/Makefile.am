NULL = 

AM_CPPFLAGS = \
	$(GENERAL_IN_VALA_CFLAGS) \
	-include $(CONFIG_HEADER) \
	$(NULL)

bin_PROGRAMS = general_in_vala

general_in_vala_SOURCES = \
	main.vala \
	components/listview.vala \
	components/directorymodel.vala \
	components/mymodel.vala \
	$(NULL)

general_in_vala_VALAFLAGS = --pkg gtk+-2.0 --pkg gee-1.0

general_in_vala_LDADD = \
	$(GENERAL_IN_VALA_LIBS) \
	$(NULL)

EXTRA_DIST = \
	$(NULL)

DISTCLEANFILES = \
	$(NULL)

