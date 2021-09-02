#include "RetroEngine.hpp"

void TitleScreen_Create(void *objPtr)
{
    RSDK_THIS(TitleScreen);
    int heading  = 0;
    int labelTex = 0;
    int textTex  = 0;

    entity->state          = 0;
    entity->introRectAlpha = 320.0;
    entity->logoTextureID  = LoadTexture("Data/Game/Menu/SonicLogo.png", TEXFMT_RGBA8888);
    ResetBitmapFonts();
    if (Engine.useHighResAssets)
        heading = LoadTexture("Data/Game/Menu/Heading_EN.png", TEXFMT_RGBA4444);
    else
        heading = LoadTexture("Data/Game/Menu/Heading_EN@1x.png", TEXFMT_RGBA4444);
    LoadBitmapFont("Data/Game/Menu/Heading_EN.fnt", FONT_HEADING, heading);

    if (Engine.useHighResAssets)
        labelTex = LoadTexture("Data/Game/Menu/Label_EN.png", TEXFMT_RGBA4444);
    else
        labelTex = LoadTexture("Data/Game/Menu/Label_EN@1x.png", TEXFMT_RGBA4444);
    LoadBitmapFont("Data/Game/Menu/Label_EN.fnt", FONT_LABEL, labelTex);

    textTex = LoadTexture("Data/Game/Menu/Text_EN.png", TEXFMT_RGBA4444);
    LoadBitmapFont("Data/Game/Menu/Text_EN.fnt", FONT_TEXT, textTex);

    entity->labelPtr         = CREATE_ENTITY(TextLabel);
    entity->labelPtr->fontID = FONT_HEADING;
    entity->labelPtr->scale  = 0.15;

    switch (Engine.language) {
        case RETRO_ES: entity->labelPtr->scale = 0.125; break;
        case RETRO_JP:
            entity->labelPtr->scale = 0.1;
            heading                 = LoadTexture("Data/Game/Menu/Heading_JA@1x.png", TEXFMT_RGBA4444);
            LoadBitmapFont("Data/Game/Menu/Heading_JA.fnt", FONT_HEADING, heading);

            labelTex = LoadTexture("Data/Game/Menu/Label_JA@1x.png", TEXFMT_RGBA4444);
            LoadBitmapFont("Data/Game/Menu/Label_JA.fnt", FONT_LABEL, labelTex);

            textTex = LoadTexture("Data/Game/Menu/Text_JA@1x.png", TEXFMT_RGBA4444);
            LoadBitmapFont("Data/Game/Menu/Text_JA.fnt", FONT_TEXT, textTex);
            break;
        case 7:
            entity->labelPtr->scale = 0.08;
            if (Engine.useHighResAssets)
                heading = LoadTexture("Data/Game/Menu/Heading_RU.png", TEXFMT_RGBA4444);
            else
                heading = LoadTexture("Data/Game/Menu/Heading_RU@1x.png", TEXFMT_RGBA4444);
            LoadBitmapFont("Data/Game/Menu/Heading_RU.fnt", FONT_HEADING, heading);

            if (Engine.useHighResAssets)
                labelTex = LoadTexture("Data/Game/Menu/Label_RU.png", TEXFMT_RGBA4444);
            else
                labelTex = LoadTexture("Data/Game/Menu/Label_RU@1x.png", TEXFMT_RGBA4444);
            LoadBitmapFont("Data/Game/Menu/Label_RU.fnt", FONT_LABEL, labelTex);
            break;
        case RETRO_KO:
            heading = LoadTexture("Data/Game/Menu/Heading_KO@1x.png", TEXFMT_RGBA4444);
            LoadBitmapFont("Data/Game/Menu/Heading_KO.fnt", FONT_HEADING, heading);

            labelTex = LoadTexture("Data/Game/Menu/Label_KO@1x.png", TEXFMT_RGBA4444);
            LoadBitmapFont("Data/Game/Menu/Label_KO.fnt", FONT_LABEL, labelTex);

            textTex = LoadTexture("Data/Game/Menu/Text_KO.png", TEXFMT_RGBA4444);
            LoadBitmapFont("Data/Game/Menu/Text_KO.fnt", FONT_TEXT, textTex);
            break;
        case RETRO_ZH:
            heading = LoadTexture("Data/Game/Menu/Heading_ZH@1x.png", TEXFMT_RGBA4444);
            LoadBitmapFont("Data/Game/Menu/Heading_ZH.fnt", FONT_HEADING, heading);

            labelTex = LoadTexture("Data/Game/Menu/Label_ZH@1x.png", TEXFMT_RGBA4444);
            LoadBitmapFont("Data/Game/Menu/Label_ZH.fnt", FONT_LABEL, labelTex);

            textTex = LoadTexture("Data/Game/Menu/Text_ZH@1x.png", TEXFMT_RGBA4444);
            LoadBitmapFont("Data/Game/Menu/Text_ZH.fnt", FONT_TEXT, textTex);
            break;
        case RETRO_ZS:
            heading = LoadTexture("Data/Game/Menu/Heading_ZHS@1x.png", TEXFMT_RGBA4444);
            LoadBitmapFont("Data/Game/Menu/Heading_ZHS.fnt", FONT_HEADING, heading);
            labelTex = LoadTexture("Data/Game/Menu/Label_ZHS@1x.png", TEXFMT_RGBA4444);
            LoadBitmapFont("Data/Game/Menu/Label_ZHS.fnt", FONT_LABEL, labelTex);
            textTex = LoadTexture("Data/Game/Menu/Text_ZHS@1x.png", TEXFMT_RGBA4444);
            LoadBitmapFont("Data/Game/Menu/Text_ZHS.fnt", FONT_TEXT, textTex);
            break;
        default: break;
    }
    entity->labelPtr->alpha = 0;
    entity->labelPtr->state = -1;

    ushort *str = NULL;
    if (Engine.gameDeviceType == RETRO_MOBILE)
        SetStringToFont(entity->labelPtr->text, strTouchToStart, FONT_HEADING);
    else
        SetStringToFont(entity->labelPtr->text, strPressStart, FONT_HEADING);

    entity->labelPtr->alignPtr(entity->labelPtr, 1);

    entity->labelPtr->x    = 64.0;
    entity->labelPtr->y    = -96.0;
    entity->introTextureID = LoadTexture("Data/Game/Menu/Intro.png", TEXFMT_RGBA5551);

    int package = 0;
    switch (Engine.globalBoxRegion) {
        case REGION_JP:
            package           = LoadTexture("Data/Game/Models/Package_JP.png", TEXFMT_RGBA5551);
            entity->introMesh = LoadMesh("Data/Game/Models/Intro.bin", entity->introTextureID);
            entity->boxMesh   = LoadMesh("Data/Game/Models/JPBox.bin", package);
            entity->cartMesh  = LoadMesh("Data/Game/Models/JPCartridge.bin", package);
            break;
        case REGION_US:
            package           = LoadTexture("Data/Game/Models/Package_US.png", TEXFMT_RGBA5551);
            entity->introMesh = LoadMesh("Data/Game/Models/Intro.bin", entity->introTextureID);
            entity->boxMesh   = LoadMesh("Data/Game/Models/Box.bin", package);
            entity->cartMesh  = LoadMesh("Data/Game/Models/Cartridge.bin", package);
            break;
        case REGION_EU:
            package           = LoadTexture("Data/Game/Models/Package_EU.png", TEXFMT_RGBA5551);
            entity->introMesh = LoadMesh("Data/Game/Models/Intro.bin", entity->introTextureID);
            entity->boxMesh   = LoadMesh("Data/Game/Models/Box.bin", package);
            entity->cartMesh  = LoadMesh("Data/Game/Models/Cartridge.bin", package);
            break;
    }

    SetMeshAnimation(entity->boxMesh, &entity->meshAnimator, 16, 16, 0.0);
    AnimateMesh(entity->boxMesh, &entity->meshAnimator);
    SetMeshAnimation(entity->introMesh, &entity->meshAnimator, 0, 36, 0.09);
    entity->field_38  = 160.0;
    entity->meshScale = 0.0;
    entity->rotationY = 0.0;
    SetMusicTrack("MenuIntro.ogg", 0, false, 0);
    SetMusicTrack("MainMenu.ogg", 1, true, 106596);
    LoadTexture("Data/Game/Menu/Circle.png", TEXFMT_RGBA4444);
    LoadTexture("Data/Game/Menu/BG1.png", TEXFMT_RGBA4444);
    LoadTexture("Data/Game/Menu/ArrowButtons.png", TEXFMT_RGBA4444);
    if (Engine.gameDeviceType == RETRO_MOBILE)
        LoadTexture("Data/Game/Menu/VirtualDPad.png", TEXFMT_RGBA8888);
    else
        LoadTexture("Data/Game/Menu/Generic.png", TEXFMT_RGBA8888);
    LoadTexture("Data/Game/Menu/PlayerSelect.png", TEXFMT_RGBA8888);
    LoadTexture("Data/Game/Menu/SegaID.png", TEXFMT_RGBA8888);
}
void TitleScreen_Main(void *objPtr)
{
    RSDK_THIS(TitleScreen);

    switch (entity->state) {
        case 0: {
            PlayMusic(0, 0);
            entity->state = 1;
            SetRenderBlendMode(RENDER_BLEND_ALPHA);
            RenderRect(-SCREEN_CENTERX_F, SCREEN_CENTERY_F, 160.0, SCREEN_XSIZE_F, SCREEN_YSIZE_F, 0, 0, 0, entity->introRectAlpha);
            break;
        }
        case 1: {
            SetRenderBlendMode(RENDER_BLEND_NONE);
            RenderRect(-SCREEN_CENTERX_F, SCREEN_CENTERY_F, 160.0, SCREEN_XSIZE_F, SCREEN_YSIZE_F, 255, 255, 255, 255);
            entity->meshAnimator.animationSpeed = 6.0 * Engine.deltaTime;
            AnimateMesh(entity->introMesh, &entity->meshAnimator);
            RenderMesh(entity->introMesh, MESH_COLOURS, true);
            SetRenderBlendMode(RENDER_BLEND_ALPHA);

            if (Engine.gameDeviceType == RETRO_MOBILE && entity->introAlpha < 0x100 && entity->introRectAlpha < 0.0) {
                entity->introAlpha += 8;
            }
            RenderImage(SCREEN_CENTERX_F - 32.0, 104.0, 160.0, 0.25, 0.25, 32.0, 32.0, 64.0, 64.0, 704.0, 544.0, entity->introAlpha,
                        entity->introTextureID);
            entity->introRectAlpha -= (300.0 * Engine.deltaTime);
            if (entity->introRectAlpha < -320.0)
                entity->state = 2;
            RenderRect(-SCREEN_CENTERX_F, SCREEN_CENTERY_F, 160.0, SCREEN_XSIZE_F, SCREEN_YSIZE_F, 0, 0, 0, entity->introRectAlpha);
            CheckKeyDown(&keyDown);
            CheckKeyPress(&keyPress);

            if (touches > 0 && entity->introRectAlpha > 0.0) {
                if (CheckTouchRect(SCREEN_CENTERX_F - 32.0, 104.0, 20.0, 20.0) >= 0) {
                    entity->state                 = 4;
                    entity->x                     = -96.0;
                    entity->meshScale             = 1.0;
                    entity->field_38              = -48.0;
                    entity->field_12C             = 256;
                    entity->logoAlpha             = 256;
                    entity->field_130             = 1;
                    NativeEntity_TextLabel *label = entity->labelPtr;
                    label->alpha                  = 256;
                    label->state                  = 1;
                }
            }
            else if (keyPress.start || keyPress.A) {
                entity->state                 = 4;
                entity->x                     = -96.0;
                entity->meshScale             = 1.0;
                entity->field_38              = -48.0;
                entity->field_12C             = 256;
                entity->logoAlpha             = 256;
                entity->field_130             = 1;
                NativeEntity_TextLabel *label = entity->labelPtr;
                label->alpha                  = 256;
                label->state                  = 1;
            }
            break;
        }
        case 2: {
            CheckKeyDown(&keyDown);
            CheckKeyPress(&keyPress);
            SetRenderBlendMode(RENDER_BLEND_NONE);
            RenderRect(-SCREEN_CENTERX_F, SCREEN_CENTERY_F, 160.0, SCREEN_XSIZE_F, SCREEN_YSIZE_F, 255, 255, 255, 255);
            entity->meshAnimator.animationSpeed = 6.0 * Engine.deltaTime;
            AnimateMesh(entity->introMesh, &entity->meshAnimator);
            RenderMesh(entity->introMesh, MESH_COLOURS, true);
            SetRenderBlendMode(RENDER_BLEND_ALPHA);
            RenderImage(SCREEN_CENTERX_F - 32.0, 104.0, 160.0, 0.25, 0.25, 32.0, 32.0, 64.0, 64.0, 704.0, 544.0, entity->introAlpha,
                        entity->introTextureID);
            if (entity->meshAnimator.frameID > 26)
                entity->state = 3;

            if (touches > 0) {
                if (CheckTouchRect(SCREEN_CENTERX_F - 32.0, 104.0, 20.0, 20.0) >= 0) {
                    entity->state                 = 4;
                    entity->x                     = -96.0;
                    entity->meshScale             = 1.0;
                    entity->field_38              = -48.0;
                    entity->field_12C             = 256;
                    entity->logoAlpha             = 256;
                    entity->field_130             = 1;
                    NativeEntity_TextLabel *label = entity->labelPtr;
                    label->alpha                  = 256;
                    label->state                  = 1;
                }
            }
            else if (keyPress.start || keyPress.A) {
                entity->state                 = 4;
                entity->x                     = -96.0;
                entity->meshScale             = 1.0;
                entity->field_38              = -48.0;
                entity->field_12C             = 256;
                entity->logoAlpha             = 256;
                entity->field_130             = 1;
                NativeEntity_TextLabel *label = entity->labelPtr;
                label->alpha                  = 256;
                label->state                  = 1;
            }
            break;
        }
        case 3: {
            SetRenderBlendMode(RENDER_BLEND_NONE);
            RenderRect(-SCREEN_CENTERX_F, SCREEN_CENTERY_F, 160.0, SCREEN_XSIZE_F, SCREEN_YSIZE_F, 255, 255, 255, 255);

            float y = 0;
            if (entity->field_38 > -48.0) {
                entity->field_38 -= (300.0 * Engine.deltaTime);
                if (entity->field_38 >= -48.0) {
                    y = entity->field_38 + 240.0;
                }
                else {
                    entity->field_38 = -48.0;
                    y                = 192.0;
                }
            }
            else {
                y = entity->field_38 + 240.0;
            }
            RenderRect(-SCREEN_CENTERX_F, y, 160.0, SCREEN_XSIZE_F, 256.0, 160, 192, 255, 255);
            RenderRect(-SCREEN_CENTERX_F, entity->field_38, 160.0, SCREEN_XSIZE_F, 16.0, 0, 0, 0, 255);
            entity->meshAnimator.animationSpeed = 6.0 * Engine.deltaTime;
            AnimateMesh(entity->introMesh, &entity->meshAnimator);
            RenderMesh(entity->introMesh, MESH_COLOURS, true);

            if (entity->meshScale < 1.0) {
                entity->meshScale += (0.75 * Engine.deltaTime);
                if (entity->meshScale > 1.0)
                    entity->meshScale = 1.0;
            }
            else {
                NativeEntity_TextLabel *label = entity->labelPtr;
                label->state                  = 1;
                entity->state                 = 4;
                entity->x                     = 0.0;
            }
            entity->rotationY += Engine.deltaTime;
            matrixScaleXYZF(&entity->renderMatrix, entity->meshScale, entity->meshScale, entity->meshScale);
            matrixRotateYF(&entity->matrix3, entity->rotationY);
            matrixMultiplyF(&entity->renderMatrix, &entity->matrix3);
            matrixTranslateXYZF(&entity->matrix3, 0.0, 0.0, 200.0);
            matrixMultiplyF(&entity->renderMatrix, &entity->matrix3);
            SetRenderMatrix(&entity->renderMatrix);
            RenderMesh(entity->boxMesh, MESH_NORMALS, true);
            SetRenderMatrix(NULL);
            SetRenderBlendMode(RENDER_BLEND_ALPHA);
            RenderImage(SCREEN_CENTERX_F - 32.0, 104.0, 160.0, 0.25, 0.25, 32.0, 32.0, 64.0, 64.0, 704.0, 544.0, entity->introAlpha,
                        entity->introTextureID);
            break;
        }
        case 4: {
            SetRenderBlendMode(RENDER_BLEND_NONE);
            RenderRect(-SCREEN_CENTERX_F, SCREEN_CENTERY, 160.0, SCREEN_XSIZE_F, SCREEN_YSIZE_F, 255, 255, 255, 255);
            RenderRect(-SCREEN_CENTERX_F, entity->field_38 + 240.0, 160.0, SCREEN_XSIZE_F, 256.0, 160, 192, 255, 255);
            RenderRect(-SCREEN_CENTERX_F, entity->field_38, 160.0, SCREEN_XSIZE_F, 16.0, 0, 0, 0, 255);

            entity->rotationY += Engine.deltaTime;
            if (entity->rotationY > M_PI * 2)
                entity->rotationY -= M_PI * 2;

            if (entity->x <= -96.0) {
                if (entity->logoAlpha > 255) {
                    CheckKeyDown(&keyDown);
                    CheckKeyPress(&keyPress);
                    if (keyPress.start || touches > 0 || keyPress.A) {
                        if (!entity->field_130) {
                            PlaySfxByName("Menu Select", false);
                            StopMusic(true);
                            entity->labelPtr->state = 2;
                            entity->introRectAlpha  = 0.0;
                            entity->state           = 5;
                        }
                    }
                    else {
                        entity->field_130 = 0;
                    }
                }
                else {
                    entity->logoAlpha += 8;
                    entity->labelPtr->alpha += 8;
                }
            }
            else {
                entity->x += ((-97.0 - entity->x) / ((Engine.deltaTime * 60.0) * 16.0));
            }
            NewRenderState();
            matrixScaleXYZF(&entity->renderMatrix, entity->meshScale, entity->meshScale, entity->meshScale);
            matrixRotateYF(&entity->matrix3, entity->rotationY);
            matrixMultiplyF(&entity->renderMatrix, &entity->matrix3);
            matrixTranslateXYZF(&entity->matrix3, entity->x, 0.0, 200.0);
            matrixMultiplyF(&entity->renderMatrix, &entity->matrix3);
            SetRenderMatrix(&entity->renderMatrix);
            RenderMesh(entity->boxMesh, MESH_NORMALS, true);
            SetRenderMatrix(NULL);
            SetRenderBlendMode(RENDER_BLEND_ALPHA);

            if (entity->introAlpha > 0) {
                entity->introAlpha -= 8;
            }
            RenderImage(SCREEN_CENTERX_F - 32.0, 104.0, 160.0, 0.25, 0.25, 32.0, 32.0, 64.0, 64.0, 704.0, 544.0, entity->introAlpha,
                        entity->introTextureID);
            RenderImage(64.0, 32.0, 160.0, 0.3, 0.3, 256.0, 128.0, 512.0, 256.0, 0.0, 0.0, entity->logoAlpha, entity->logoTextureID);

            if (entity->field_12C > 0) {
                entity->field_12C -= 32;
                RenderRect(-SCREEN_CENTERX_F, SCREEN_CENTERY_F, 160.0, SCREEN_XSIZE_F, SCREEN_YSIZE_F, 255, 255, 255, entity->field_12C);
            }
            break;
        }
        case 5: {
            SetRenderBlendMode(RENDER_BLEND_NONE);
            RenderRect(-SCREEN_CENTERX_F, SCREEN_CENTERY_F, 160.0, SCREEN_XSIZE_F, SCREEN_YSIZE_F, 255, 255, 255, 255);
            RenderRect(-SCREEN_CENTERX_F, entity->field_38 + 240.0, 160.0, SCREEN_XSIZE_F, 256.0, 160, 192, 255, 255);
            RenderRect(-SCREEN_CENTERX_F, entity->field_38, 160.0, SCREEN_XSIZE_F, 16.0, 0, 0, 0, 255);

            float div = (60.0 * Engine.deltaTime) * 1.125;
            entity->x /= div;
            entity->rotationY /= div;
            NewRenderState();
            matrixRotateYF(&entity->renderMatrix, entity->rotationY);
            matrixTranslateXYZF(&entity->matrix3, entity->x, 0.0, 200.0);
            matrixMultiplyF(&entity->renderMatrix, &entity->matrix3);
            SetRenderMatrix(&entity->renderMatrix);
            RenderMesh(entity->boxMesh, MESH_NORMALS, true);
            SetRenderMatrix(NULL);
            SetRenderBlendMode(RENDER_BLEND_ALPHA);

            if (entity->logoAlpha > 0)
                entity->logoAlpha -= 8;

            entity->introRectAlpha += Engine.deltaTime;
            if (entity->introRectAlpha > 1.0) {
                entity->state                 = 6;
                NativeEntity_TextLabel *label = entity->labelPtr;
                RemoveNativeObject(label);
                SetMeshAnimation(entity->boxMesh, &entity->meshAnimator, 4, 16, 0.0);
                entity->meshAnimator.animationTimer = 0.0;
                entity->meshAnimator.frameID        = 16;
                entity->matrixZ                     = 200.0;
                entity->field_3C                    = 4.0;
                entity->rotationZ                   = DegreesToRad(-90.0);
            }
            RenderImage(64.0, 32.0, 160.0, 0.3, 0.31, 256.0, 128.0, 512.0, 256.0, 0.0, 0.0, entity->logoAlpha, entity->logoTextureID);
            break;
        }
        case 6: {
            SetRenderBlendMode(RENDER_BLEND_NONE);
            RenderRect(-SCREEN_CENTERX_F, SCREEN_CENTERY_F, 160.0, SCREEN_XSIZE_F, SCREEN_YSIZE_F, 255, 255, 255, 255);
            RenderRect(-SCREEN_CENTERX_F, SCREEN_CENTERY_F, 160.0, SCREEN_XSIZE_F, SCREEN_CENTERY_F - entity->field_38, 160, 192, 255, 255);
            RenderRect(-SCREEN_CENTERX_F, entity->field_38, 160.0, SCREEN_XSIZE_F, 16.0, 0, 0, 0, 255);
            entity->meshAnimator.animationSpeed = -16.0 * Engine.deltaTime;
            AnimateMesh(entity->boxMesh, &entity->meshAnimator);

            float val  = 60.0 * Engine.deltaTime;
            float val2 = 0.125 * val;

            entity->field_3C = (entity->field_3C - val2) - val2;
            entity->field_38 += (val * (entity->field_3C - val2));
            if (entity->meshAnimator.frameID <= 7) {
                if (entity->rotationY < 1.0)
                    entity->rotationY += Engine.deltaTime;
                entity->field_50 = (entity->field_50 - val2) - val2;
                entity->field_4C += (val * (entity->field_50 - val2));
                entity->matrixY += ((16.0 - entity->matrixY) / (val * 16.0));

                entity->matrixZ += ((152.0 - entity->matrixZ) / (val * 16.0));
                entity->rotationZ += ((0.0 - entity->rotationZ) / (val * 22.0));
            }
            NewRenderState();
            matrixRotateXF(&entity->renderMatrix, entity->rotationY);
            matrixTranslateXYZF(&entity->matrix3, entity->x, entity->field_4C, 200.0);
            matrixMultiplyF(&entity->renderMatrix, &entity->matrix3);
            SetRenderMatrix(&entity->renderMatrix);
            RenderMesh(entity->boxMesh, MESH_NORMALS, true);

            matrixRotateXYZF(&entity->matrix2, 0.0, 0.0, entity->rotationZ);
            matrixTranslateXYZF(&entity->matrix3, 0.0, entity->matrixY, entity->matrixZ);
            matrixMultiplyF(&entity->matrix2, &entity->matrix3);
            SetRenderMatrix(&entity->matrix2);
            RenderMesh(entity->cartMesh, MESH_NORMALS, true);
            SetRenderMatrix(NULL);
            if (entity->field_4C < -360.0) {
                ShowPromoPopup(0, "BootupPromo");
                ResetNativeObject(entity, MenuControl_Create, MenuControl_Main);
            }
            break;
        }
        default: break;
    }
}