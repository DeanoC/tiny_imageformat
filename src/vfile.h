#pragma once

typedef struct VFile_Interface_t *VFile_Handle;

enum VFile_SeekDir
{
    VFile_SD_Begin = 0,
    VFile_SD_Current,
    VFile_SD_End,
};

enum
{
    VFile_Type_Invalid = 0,
    VFile_Type_OsFile = 1,
    VFile_Type_Memory = 2
};

enum Os_FileMode
{
    Os_FM_Write
};

extern "C"
{
    VFile_Handle VFile_FromFile(char const *filename, enum Os_FileMode mode);
    VFile_Handle VFile_FromMemory(void const *memory, size_t size, bool takeOwnership);
    VFile_Handle VFile_ToBuffer(size_t initialSize);

    void VFile_Close(VFile_Handle handle);
    void VFile_Flush(VFile_Handle handle);
    size_t VFile_Read(VFile_Handle handle, void *buffer, size_t byteCount);
    size_t VFile_Write(VFile_Handle handle, void const *buffer, size_t byteCount);
    bool VFile_Seek(VFile_Handle handle, int64_t offset, enum VFile_SeekDir origin);
    int64_t VFile_Tell(VFile_Handle handle);
    size_t VFile_Size(VFile_Handle handle);
    char const *VFile_GetName(VFile_Handle handle);
    bool VFile_IsEOF(VFile_Handle handle);
    uint32_t VFile_GetType(VFile_Handle handle);
    void *VFile_GetTypeSpecificData(VFile_Handle handle);
}