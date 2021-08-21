;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 4.1.6 #12439 (MINGW32)
;--------------------------------------------------------
	.module main
	.optsdcc -mgbz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _main
	.globl _initializePlayer
	.globl _playerUpdate
	.globl _malloc
	.globl _printf
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
;player.c:18: int playerUpdate(){
;	---------------------------------
; Function playerUpdate
; ---------------------------------
_playerUpdate::
;c:/gbdk/include/gb/gb.h:1263: OAM_item_t * itm = &shadow_OAM[nb];
	ld	bc, #_shadow_OAM+0
;c:/gbdk/include/gb/gb.h:1264: itm->y+=y, itm->x+=x;
	ld	a, (bc)
	inc	a
	ld	(bc), a
	inc	bc
	ld	a, (bc)
	inc	a
	ld	(bc), a
;player.c:20: return 0;
	ld	de, #0x0000
;player.c:21: }
	ret
;player.c:23: Player *initializePlayer(){
;	---------------------------------
; Function initializePlayer
; ---------------------------------
_initializePlayer::
;player.c:24: Player * p = malloc(sizeof(Player));
	ld	de, #0x000d
	push	de
	call	_malloc
	pop	hl
;player.c:25: p->canFire = true;
	ld	hl, #0x0004
	add	hl, de
	ld	(hl), #0x00
;player.c:26: p->timeSinceLastUpdate = 100;
	ld	hl, #0x0009
	add	hl, de
	ld	a, #0x64
	ld	(hl+), a
	ld	(hl), #0x00
;player.c:27: p->xVelocity = 1;
	ld	hl, #0x0005
	add	hl, de
	ld	a, #0x01
	ld	(hl+), a
	ld	(hl), #0x00
;player.c:28: p->yVelocity = 0;
	ld	hl, #0x0007
	add	hl, de
	xor	a, a
	ld	(hl+), a
	ld	(hl), a
;player.c:29: p->playerUpdate = playerUpdate;
	ld	hl, #0x000b
	add	hl, de
	ld	c, l
	ld	b, h
	ld	(hl), #<(_playerUpdate)
	inc	bc
	ld	a, #>(_playerUpdate)
	ld	(bc), a
;player.c:30: set_sprite_data(0,1,Turret);
	push	de
	ld	bc, #_Turret
	push	bc
	xor	a, a
	inc	a
	push	af
	call	_set_sprite_data
	add	sp, #4
	pop	de
;c:/gbdk/include/gb/gb.h:1174: shadow_OAM[nb].tile=tile;
	ld	bc, #_shadow_OAM+2
	xor	a, a
	ld	(bc), a
;c:/gbdk/include/gb/gb.h:1247: OAM_item_t * itm = &shadow_OAM[nb];
	ld	hl, #_shadow_OAM
;c:/gbdk/include/gb/gb.h:1248: itm->y=y, itm->x=x;
	ld	a, #0x32
	ld	(hl+), a
	ld	(hl), #0x32
;player.c:34: return p; 
;player.c:35: }
	ret
;main.c:6: void main(){
;	---------------------------------
; Function main
; ---------------------------------
_main::
	dec	sp
	dec	sp
;main.c:8: SHOW_SPRITES;
	ldh	a, (_LCDC_REG + 0)
	or	a, #0x02
	ldh	(_LCDC_REG + 0), a
;main.c:10: Player *p = initializePlayer();
	call	_initializePlayer
	ld	c, e
	ld	b, d
;main.c:12: printf("%i", p->timeSinceLastUpdate);
	ld	hl, #0x0009
	add	hl, bc
	ld	e, l
	ld	d, h
	ld	a, (de)
	ldhl	sp,	#0
	ld	(hl+), a
	inc	de
	ld	a, (de)
	ld	(hl), a
	push	bc
	ldhl	sp,	#2
	ld	a, (hl+)
	ld	e, a
	ld	d, (hl)
	push	de
	ld	de, #___str_0
	push	de
	call	_printf
	add	sp, #4
	ld	de, #0x0bb8
	push	de
	call	_delay
	pop	hl
	pop	bc
;main.c:14: while(1){
00102$:
;main.c:16: delay(500);
	push	bc
	ld	de, #0x01f4
	push	de
	call	_delay
	pop	hl
	pop	bc
;main.c:17: p->playerUpdate();
	ld	hl, #0x000b
	add	hl, bc
	ld	a,	(hl+)
	ld	h, (hl)
;	spillPairReg hl
	ld	l, a
;	spillPairReg hl
;	spillPairReg hl
	push	bc
	call	___sdcc_call_hl
	pop	bc
	jr	00102$
;main.c:21: }
	inc	sp
	inc	sp
	ret
___str_0:
	.ascii "%i"
	.db 0x00
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
