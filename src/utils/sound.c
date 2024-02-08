#include <utils/sound.h>

// 播放音效
void PlayChunk(char *address)
{
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        MIXER_HANDLE_ERROR("initialize");
    }

    if (Mix_AllocateChannels(1) < 0) {
        MIXER_HANDLE_ERROR("allocate channels");
    }

    Mix_Chunk *chunk = Mix_LoadWAV(address);
    if (chunk == NULL) {
        MIXER_HANDLE_ERROR("load wave file");
    }

    if (Mix_PlayChannel(-1, chunk, 0) < 0) {
        MIXER_HANDLE_ERROR("play channel");
    }

    SDL_Delay(getChunkTimeMilliseconds(chunk) + WAITING_TIME);

    Mix_FreeChunk(chunk);
}

Uint32 getChunkTimeMilliseconds(Mix_Chunk *chunk)
{
    Uint32 points = 0;
    Uint32 frames = 0;
    int freq = 0;
    Uint16 fmt = 0;
    int chans = 0;

    if (!Mix_QuerySpec(&freq, &fmt, &chans)) {
        return 0;
    }
    points = (chunk->alen / ((fmt & 0xFF) / 8));
    frames = (points / chans);
    return ((frames * 1000) / freq);
}
