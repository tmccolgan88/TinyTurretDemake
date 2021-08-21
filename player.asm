;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 4.1.6 #12439 (MINGW32)
;--------------------------------------------------------
	.module player
	.optsdcc -mgbz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _update
	.globl _initializePlayer
	.globl _set_sprite_data
	.globl _delay
	.globl _Turret
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _DATA
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _INITIALIZED
_Turret::
	.ds 16
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area _DABS (ABS)
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area _HOME
	.area _GSINIT
	.area _GSFINAL
	.area _GSINIT
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area _HOME
	.area _HOME
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area _CODE
;player.c:16: Player *initializePlayer(){
;	---------------------------------
; Function initializePlayer
; ---------------------------------
_initializePlayer::
	add	sp, #-9
;player.c:18: p.canFire = true;
	ldhl	sp,	#0
	ld	c, l
	ld	b, h
	ld	hl, #0x0004
	add	hl, bc
	ld	(hl), #0x00
;player.c:19: p.timeSinceLastUpdate = 100;
	ld	hl, #0x0005
	add	hl, bc
	ld	a, #0x64
	ld	(hl+), a
	ld	(hl), #0x00
;player.c:21: set_sprite_data(0,1,Turret);
	ld	de, #_Turret
	push	de
	xor	a, a
	inc	a
	push	af
	call	_set_sprite_data
	add	sp, #4
;c:/gbdk/include/gb/gb.h:1174: shadow_OAM[nb].tile=tile;
	ld	hl, #(_shadow_OAM + 2)
	ld	(hl), #0x00
;c:/gbdk/include/gb/gb.h:1247: OAM_item_t * itm = &shadow_OAM[nb];
	ld	hl, #_shadow_OAM
;c:/gbdk/include/gb/gb.h:1248: itm->y=y, itm->x=x;
	ld	a, #0x32
	ld	(hl+), a
	ld	(hl), #0x32
;player.c:25: return &p; 
	ld	e, c
	ld	d, b
;player.c:26: }
	add	sp, #9
	ret
;player.c:27: void update(){
;	---------------------------------
; Function update
; ---------------------------------
_update::
;player.c:29: delay(2000);
	ld	de, #0x07d0
	push	de
	call	_delay
	pop	hl
;c:/gbdk/include/gb/gb.h:1263: OAM_item_t * itm = &shadow_OAM[nb];
	ld	bc, #_shadow_OAM+0
;c:/gbdk/include/gb/gb.h:1264: itm->y+=y, itm->x+=x;
	ld	a, (bc)
	add	a, #0x02
	ld	(bc), a
	inc	bc
	ld	a, (bc)
	add	a, #0x02
	ld	(bc), a
;player.c:30: scroll_sprite(0, 2,2);
;player.c:31: }
	ret
	.area _CODE
	.area _INITIALIZER
__xinit__Turret:
	.db #0x3c	; 60
	.db #0x3c	; 60
	.db #0x18	; 24
	.db #0x18	; 24
	.db #0x18	; 24
	.db #0x18	; 24
	.db #0x18	; 24
	.db #0x18	; 24
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xbd	; 189
	.db #0xc3	; 195
	.db #0xbd	; 189
	.db #0xc3	; 195
	.db #0xff	; 255
	.db #0xff	; 255
	.area _CABS (ABS)
