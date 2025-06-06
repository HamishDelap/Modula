#pragma once
#include <juce_audio_processors/juce_audio_processors.h>

class WaveformProcessor
{
public:
    WaveformProcessor(double sampleRate, double bufferTime, int numChannels = 1);
    
    void PushBuffer(juce::AudioBuffer<float>& inBuffer);
    bool PullBuffer(juce::AudioBuffer<float>& outBuffer);

private:
    int m_numChannels = 0;
    int m_bufferSize = 0;
    juce::AbstractFifo m_fifo;
    juce::OwnedArray<juce::AudioBuffer<float>> m_buffer;
};
